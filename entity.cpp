#include "entity.h"
#include <iostream>
#include "item.h"
#include "creature.h"
#include "room.h"
#include "utils.h"

Entity::Entity(const std::string name, const std::string description)
    : name(name), description(description), entityType(EntityType::ITEM) {}

Entity::~Entity() {}

void Entity::lookAt() {
    std::cout << "You see " << this->description << std::endl;
}

int Entity::useItem(Item* item) {
    std::cout << "You use the item " << item->name << " on " << this->name << std::endl;
    return 0;
}

void Entity::beTakenByCreature(Creature* creature, Room* room) {
    std::cout << "The creature " << creature->name << " takes the item " << this->name << std::endl;
}