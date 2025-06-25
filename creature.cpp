#include "creature.h"
#include <iostream>

Creature::Creature(const std::string name) : name(name){}

Creature::~Creature() {}

void Creature::takeItem(Entity* item) {
	this->inventory.push_back(item);
}