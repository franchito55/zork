#include "world.h"
#include "room.h"

World::World() {
	this->currentRoom = nullptr;
}

void World::AddRoom(Room* room) {
	rooms.push_back(room);
}

World::~World() {}