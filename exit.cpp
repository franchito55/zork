#include "exit.h"

Exit::Exit(const char* name, const char* description, ExitDirection direction, Room* source, Room* destination) : Entity(name, description) {
	this->entityType = EntityType::EXIT;
	this->direction = direction;
	this->source = source;
	this->destination = destination;
}

Exit::~Exit() {}