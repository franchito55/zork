#include "room.h"
#include "entity.h"
#include <map>

Room::Room(const char* name, const char* description)
    : Entity(name, description) {
    entityType = ROOM;
}

void Room::AddExit(Exit* exit) {
    exits.push_back(exit);
}

void Room::AddItem(Item* item) {
    items.push_back(item);
}