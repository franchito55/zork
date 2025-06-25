#pragma once
#include "entity.h"
#include <string>

class Room;
class Creature;

class Exit : public Entity {
public:
    std::string direction;
    Room* source;
    Room* destination;

    Exit(const char* name, const char* description, std::string direction, Room* source, Room* destination);
    ~Exit();
    void lookAt();
    void useItem(Item* item);
    void beTakenByCreature(Creature* creature);
};