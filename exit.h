#pragma once
#include "entity.h"

class Room;

enum ExitDirection {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Exit : public Entity {
    public:
        ExitDirection direction;
        Room* source;
        Room* destination;

        Exit(const char* name, const char* description, ExitDirection direction, Room* source, Room* destination);
        ~Exit();
};