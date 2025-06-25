#pragma once
#include <string>
#include <vector>

class Entity;
class Item;

class Creature {
public:
	std::string name;
	std::vector<Item*> inventory;
	virtual void takeItem(Item* item);

	Creature(const std::string name);
	~Creature();
};