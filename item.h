#pragma once
#include "entity.h"
#include <string>

class Room;

class Item : public Entity {
public:
    Room* location;

    Item(const std::string name, const std::string description);
    ~Item();
    void beTakenByCreature(Creature* creature, Room* room);
    void drop(Creature* creature, Room* room);
};