#include "exit.h"
#include <iostream>
#include "creature.h"
#include "utils.h"
#include "item.h"
#include "key.h"
#include "room.h"

Exit::Exit(const std::string name, const std::string description, std::string direction, Room* source, Room* destination) : Entity(name, description) {
	this->entityType = EntityType::EXIT;
	this->direction = direction;
	this->source = source;
	this->destination = destination;
}

Exit::~Exit() {}

void Exit::beTakenByCreature(Creature* creature) {
	std::cout << "You cannot take an exit." << std::endl;
}

int Exit::useItem(Item* item) {
	Key* key = dynamic_cast<Key*>(item);
	if (key) {
		if (this->destination == key->opens) {
			this->destination->locked = false;
			std::cout << "You have opened the door to " << this->destination->name << std::endl;
			return 0;
		}
		else {
			std::cout << "This key doesn't fit this keyhole" << std::endl;
		}
	}
	else {
		Utils::cannotUseItem(item, this);
		return 1;
	}
}

void Exit::lookAt() {
	std::cout << "You see an exit that leads somewhere out of this room." << std::endl;
	std::cout << this->description << std::endl;
	std::cout << "It leads " << this->direction << std::endl;
}