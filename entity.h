#pragma once

enum EntityType {
    ROOM,
    ITEM,
    PLAYER,
    EXIT
};

class Item;
class Creature;

class Entity {
public:
    const char* name;
    const char* description;
    EntityType entityType;

    Entity(const char* name, const char* description);
    virtual ~Entity();
    virtual void lookAt();
    virtual void useItem(Item* i);
    virtual void beTakenByCreature(Creature* creature);
};