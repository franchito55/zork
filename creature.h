#pragma once
#include <string>
#include <vector>

class Entity;

class Creature {
public:
	std::string name;
	std::vector<Entity*> inventory;
	virtual void takeItem(Entity* item);

	Creature(const std::string name);
	~Creature();
};