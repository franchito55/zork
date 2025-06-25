#pragma once
#include "creature.h"
#include <string>

class Player : public Creature {
public:
	Player(const std::string name);
};