#pragma once
#include "entity.h"
#include <vector>
#include <map>

class Item;
class Exit;
class Creature;

class Room : public Entity {
public:
    std::vector<Exit*> exits;
    std::vector<Item*> items;

    Room(const char* name, const char* description);
    void AddExit(Exit* exit);
    void AddItem(Item* item);
    void lookAt();
    void useItem(Item* item);
    void beTakenByCreature(Creature* creature);
};