#include <iostream>
#include "room.h"
#include "world.h"
#include "exit.h"

int main()
{
    Room* forest = new Room("Forest", "The forest in which the adventure begins");
    Room* shack = new Room("Shack", "The shack of an unknown inhabitant");

    Exit* exitForestToShack = new Exit("Suspicious space between bushes", "A path which seems man-made between some bushes, probably hidden on purpose.", ExitDirection::WEST, forest, shack);
    Exit* exitShackToForest = new Exit("Wooden door", "A wooden door, with a few deep scratches on it.", ExitDirection::EAST, shack, forest);
    forest->AddExit(exitForestToShack);
    shack->AddExit(exitShackToForest);

    World* world = new World();
    world->AddRoom(forest);
    world->AddRoom(shack);
    world->currentRoom = forest;

    bool playing = true;
    // 100 character limit on commands seems more than reasonable
    char playerCommand[100];
    std::cout << "Welcome to ZORK! In this game, you will have to travel around the map in order to find a key to enter the final room." << std::endl;
    while (playing) {
        std::cout << "You are currently in the " << world->currentRoom->description << std::endl;
        std::cout << world->currentRoom->exits.
        std::cin.getline(playerCommand, 100);
        
        std::cout << playerCommand << std::endl;
        playing = false;
    }
}