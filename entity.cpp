#include "entity.h"
#include <iostream>
#include "item.h"
#include "creature.h"

Entity::Entity(const char* name, const char* description)
    : name(name), description(description), entityType(EntityType::ITEM) {}

Entity::~Entity() {}

void Entity::lookAt() {
    std::cout << "You look at " << this->description << std::endl;
}

void Entity::useItem(Item* item) {
    std::cout << "You use the item " << item->name << " on " << this->name << std::endl;
}

void Entity::beTakenByCreature(Creature* creature) {
    std::cout << "The creature " << creature->name << " takes the item " << this->name << std::endl;
}