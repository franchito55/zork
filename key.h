#pragma once
#include "item.h"

class Room;

class Key : public Item {
public:
	Entity* opens;

	Key(const std::string name, const std::string description);
	~Key();
};