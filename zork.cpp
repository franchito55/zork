#include <iostream>
#include "room.h"
#include "world.h"
#include "exit.h"
#include "utils.h"
#include "verb.h"
#include "player.h"
#include "item.h"

int main()
{
    Utils* utils = new Utils();

    World* world = new World();

    bool playing = true;
    // 100 character limit on commands seems more than reasonable
    char playerCommand[100];
    std::cout << "Welcome to ZORK! In this game, you will have to travel around the map in order to find the scripture of a school you inherited from your father. However, it will probably be somewhere hidden..." << std::endl;
    std::cout << "Please enter your name:" << std::endl;
    std::cout << "> ";
    char playerName[100];
    std::cin.getline(playerName, 100);
    Player* player = new Player(playerName);
    while (playing) {
        std::cout << "You are currently in " << world->currentRoom->name << std::endl;
        std::cout << "You can see " << world->currentRoom->exits.size() << " exits out of this room:" << std::endl;
        for (size_t i = 0; i < world->currentRoom->exits.size(); i++) {
            std::cout << world->currentRoom->exits.at(i)->direction << ": " << world->currentRoom->exits.at(i)->destination->name << std::endl;
        }
        std::cout << "> ";
        std::cin.getline(playerCommand, 100);
        if (std::cin.fail()) {
            std::cout << "Input was too long!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::vector<std::string> playerCommandTokenized = Utils::tokenize(playerCommand);

        // We will limit sentences to 1 subject, 1 verb and 1 object
        Verb* playerCommandVerb = utils->getVerb(playerCommandTokenized);

        if (playerCommandVerb == nullptr) {
            Utils::commandNotUnderstood();
            continue;
        }
        else {
            switch (playerCommandVerb->id) {
            case 0: {
                Room* goCommandDestination = Utils::getGoCommandDestination(playerCommandTokenized, world->currentRoom);
                if (goCommandDestination == nullptr) {
                    Utils::commandNotUnderstood();
                }
                else if (goCommandDestination->locked) {
                    std::cout << "The door is locked. You will need to find a key in order to open it." << std::endl;
                }
                else {
                    std::cout << "You travel to " << goCommandDestination->name << std::endl;
                    world->currentRoom = goCommandDestination;
                }
                }
                break;
            case 1: {
                Entity* takeCommandObject = Utils::getGenericDirectObject(playerCommandTokenized, world->currentRoom, player);
                if (takeCommandObject == nullptr) {
                    Utils::commandNotUnderstood();
                }
                else {
                    takeCommandObject->beTakenByCreature(player, world->currentRoom);
                }
                }
                break;
            case 2: {
                Entity* lookCommandObject = Utils::getGenericDirectObject(playerCommandTokenized, world->currentRoom, player);
                if (lookCommandObject == nullptr) {
                    Utils::commandNotUnderstood();
                }
                else {
                    lookCommandObject->lookAt();
                }
                }
                break;
            case 3: {
                Entity* useCommandDirectObject = Utils::getGenericDirectObject(playerCommandTokenized, world->currentRoom, player);
                Entity* useCommandIndirectObject = Utils::getGenericIndirectObject(playerCommandTokenized, world->currentRoom, player);
                if (useCommandDirectObject == nullptr || useCommandIndirectObject == nullptr) {
                    Utils::commandNotUnderstood();
                }
                else {
                    try {
                        int useResult = useCommandIndirectObject->useItem((Item*)useCommandDirectObject);
                        if (useResult == 0) {
                            Utils::removeItemFromInventory((Item*)useCommandDirectObject, player);
                        }
                        else if (useResult == 2) {
                            playing = false;
                        }
                    }
                    catch (const std::bad_cast& e) {
                        Utils::cannotUseItem(useCommandDirectObject, useCommandIndirectObject);
                    }
                }
                break;
            }
            case 4: {
                world->currentRoom->explore();
                break;
            }
            case 5: {
                Entity* entityToDrop = Utils::getGenericDirectObject(playerCommandTokenized, world->currentRoom, player);
                if (entityToDrop == nullptr) {
                    Utils::commandNotUnderstood();
                    break;
                }
                Item* itemToDrop = Utils::getItemFromInventory(entityToDrop, player);
                if (itemToDrop == nullptr) {
                    std::cout << "You do not have that item in your inventory." << std::endl;
                }
                else {
                    itemToDrop->drop(player, world->currentRoom);
                }
                break;
            }
            }
        }
    }

    std::cout << "\nPresiona ENTER para salir...";
    std::cin.get();
}