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
    bool locked;

    Room(const std::string name, const std::string description, bool locked);
    void AddExit(Exit* exit);
    void AddItem(Item* item);
    void lookAt();
    int useItem(Item* item);
    void beTakenByCreature(Creature* creature);
    void explore();
};