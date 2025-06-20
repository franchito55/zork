#pragma once

enum EntityType {
    ROOM,
    ITEM,
    PLAYER,
    EXIT
};

class Entity {
    public:
        const char* name;
        const char* description;
        EntityType entityType;

        Entity(const char* name, const char* description);
        virtual ~Entity();
};