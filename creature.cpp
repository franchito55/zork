#include "creature.h"
#include <iostream>

Creature::Creature(const std::string name) : name(name){}

Creature::~Creature() {}

void Creature::takeItem(Item* item) {
	this->inventory.push_back(item);
}