#pragma once
#include <vector>
#include "room.h"

class World {
public:
	std::vector<Room*> rooms;
	Room* currentRoom;
	// TODO
	// std::vector<Creature*> creatures;

	World();
	~World();
	void AddRoom(Room* room);
	// TODO
	// void AddCreature(Creature* creature);
};