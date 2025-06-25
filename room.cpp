#include "room.h"
#include "entity.h"
#include <map>
#include <iostream>
#include "exit.h"
#include "creature.h"
#include "item.h"
#include "key.h"
#include "utils.h"

Room::Room(const std::string name, const std::string description, bool locked)
    : Entity(name, description) {
    entityType = EntityType::ROOM;
    this->locked = locked;
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
    for (size_t i = 0; i < this->exits.size(); i++) {
        std::cout << this->exits.at(i)->direction << ": leads to " << this->exits.at(i)->destination->name << std::endl;
    }
}

int Room::useItem(Item* item) {
    Utils::cannotUseItem(item, this);
    return 1;
}

void Room::beTakenByCreature(Creature* creature) {
    std::cout << "You cannot take a room." << std::endl;
}

void Room::explore() {
    std::cout << this->description << std::endl;
    if (this->items.size() > 0) {
        std::cout << "You can see some items lying on the floor:" << std::endl;
        for (size_t i = 0; i < this->items.size(); i++) {
            std::cout << this->items.at(i)->name << ": " << this->items.at(i)->description << std::endl;
        }
    }
}