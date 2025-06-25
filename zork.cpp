#include <iostream>
#include "room.h"
#include "world.h"
#include "exit.h"
#include "utils.h"
#include "verb.h"
#include "player.h"

int main()
{
    Utils* utils = new Utils();

    World* world = new World();

    bool playing = true;
    // 100 character limit on commands seems more than reasonable
    char playerCommand[100];
    std::cout << "Welcome to ZORK! In this game, you will have to travel around the map in order to find a key to enter the final room." << std::endl;
    std::cout << "Please enter your name:" << std::endl;
    char playerName[100];
    std::cin.getline(playerName, 100);
    Player* player = new Player(playerName);
    while (playing) {
        std::cout << "You are currently in the " << world->currentRoom->description << std::endl;
        std::cout << "You can see " << world->currentRoom->exits.size() << " exits out of this room:" << std::endl;
        for (int i = 0; i < world->currentRoom->exits.size(); i++) {
            std::cout << world->currentRoom->exits.at(i)->direction << ": " << world->currentRoom->exits.at(i)->destination->name << std::endl;
        }
        std::cin.getline(playerCommand, 100);
        std::vector<std::string> playerCommandTokenized = Utils::tokenize(playerCommand);
        
        for (size_t i = 0; i < playerCommandTokenized.size(); i++) {
            std::cout << playerCommandTokenized.at(i) << std::endl;
        }

        // We will limit sentences to 1 subject, 1 verb and 1 object
        Verb* playerCommandVerb = utils->getVerb(playerCommandTokenized);

        if (playerCommandVerb == nullptr) {
            std::cout << "Sorry, I didn't understand your command" << std::endl;
            continue;
        }
        else {
            switch (playerCommandVerb->id) {
            case 0: {
                Room* goCommandDestination = Utils::getGoCommandDestination(playerCommandTokenized, world->currentRoom);
                if (goCommandDestination == nullptr) {
                    Utils::commandNotUnderstood();
                }
                else {
                    std::cout << "You travel to " << goCommandDestination << std::endl;
                    world->currentRoom = goCommandDestination;
                }
                }
                break;
            case 1: {
                Entity* takeCommandObject = Utils::getGenericDirectObject(playerCommandTokenized, world->currentRoom);
                if (takeCommandObject == nullptr) {
                    Utils::commandNotUnderstood();
                }
                else {
                    takeCommandObject->beTakenByCreature(player);
                }
                }
                break;
            case 2: {
                Entity* lookCommandObject = Utils::getGenericDirectObject(playerCommandTokenized, world->currentRoom);
                if (lookCommandObject == nullptr) {
                    Utils::commandNotUnderstood();
                }
                else {
                    lookCommandObject->lookAt();
                }
                }
                break;
            case 3: {
                Entity* useCommandDirectObject = Utils::getGenericDirectObject(playerCommandTokenized, world->currentRoom);
                Entity* useCommandIndirectObject = Utils::getGenericIndirectObject(playerCommandTokenized, world->currentRoom);
                if (useCommandDirectObject == nullptr || useCommandIndirectObject == nullptr) {
                    Utils::commandNotUnderstood();
                }
                break;
            }
            }
        }
    }
}