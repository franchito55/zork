#include "item.h"
#include <string>
#include "creature.h"
#include "utils.h"
#include "room.h"

Item::Item(const std::string name, const std::string description) : Entity(name, description) {
	entityType = EntityType::ITEM;
	this->location = nullptr;
}

Item::~Item() {}

void Item::beTakenByCreature(Creature* creature, Room* room) {
	std::cout << "You take " << this->name << std::endl;
	Utils::removeItemFromRoom(this, room);
	creature->inventory.push_back(this);
}

void Item::drop(Creature* creature, Room* room) {
	std::cout << "You dropped " << this->name << " on the floor of " << room->name << std::endl;
	Utils::removeItemFromInventory(this, creature);
	room->AddItem(this);
}