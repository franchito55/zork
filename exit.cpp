#include "exit.h"
#include <iostream>
#include "creature.h"

Exit::Exit(const char* name, const char* description, std::string direction, Room* source, Room* destination) : Entity(name, description) {
	this->entityType = EntityType::EXIT;
	this->direction = direction;
	this->source = source;
	this->destination = destination;
}

Exit::~Exit() {}

void Exit::beTakenByCreature(Creature* creature) {
	std::cout << "You cannot take an exit." << std::endl;
}

void Exit::useItem(Item* item) {
	std::cout << "You cannot use an item on an exit" << std::endl;
}

void Exit::lookAt() {
	std::cout << "You see an exit that leads somewhere out of this room." << std::endl;
	std::cout << this->description << std::endl;
	std::cout << "It leads " << this->direction << std::endl;
}