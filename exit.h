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

    Exit(const std::string name, const std::string description, std::string direction, Room* source, Room* destination);
    ~Exit();
    void lookAt();
    int useItem(Item* item);
    void beTakenByCreature(Creature* creature);
};