#include "room.h"
#include "entity.h"
#include <map>
#include <iostream>
#include "exit.h"
#include "creature.h"

Room::Room(const char* name, const char* description)
    : Entity(name, description) {
    entityType = ROOM;
}

void Room::AddExit(Exit* exit) {
    exits.push_back(exit);
}

void Room::AddItem(Item* item) {
    items.push_back(item);
}

void Room::lookAt() {
    std::cout << this->description << std::endl;
    std::cout << "You see the following exits in the room:" << std::endl;
    for (int i = 0; i < this->exits.size(); i++) {
        std::cout << this->exits.at(i)->direction << ": leads to " << this->exits.at(i)->destination->name << std::endl;
    }
}

void Room::useItem(Item* item) {

}

void Room::beTakenByCreature(Creature* creature) {
    std::cout << "You cannot take a room." << std::endl;
}