#pragma once
#include <string>

enum class EntityType {
    ROOM,
    ITEM,
    PLAYER,
    EXIT
};

class Item;
class Creature;
class Room;

class Entity {
public:
    const std::string name;
    const std::string description;
    EntityType entityType;

    Entity(const std::string name, const std::string description);
    virtual ~Entity();
    virtual void lookAt();
    virtual int useItem(Item* item);
    virtual void beTakenByCreature(Creature* creature, Room* room);
};