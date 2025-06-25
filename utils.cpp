#include "utils.h"
#include "verb.h"
#include <vector>
#include <cctype>
#include "room.h"
#include "exit.h"
#include "item.h"
#include "creature.h"
#include "entity.h"

Utils::Utils() {
    std::vector<std::string> goSynonyms;
    goSynonyms.push_back("TRAVEL");
    goSynonyms.push_back("VISIT");
    Verb* go = new Verb(0, "GO", goSynonyms);
    allowedVerbs.push_back(go);

    std::vector<std::string> takeSynonyms;
    takeSynonyms.push_back("GRAB");
    takeSynonyms.push_back("PICK");
    takeSynonyms.push_back("GET");
    Verb* take = new Verb(1, "TAKE", takeSynonyms);
    allowedVerbs.push_back(take);

    std::vector<std::string> lookSynonyms;
    lookSynonyms.push_back("SEE");
    lookSynonyms.push_back("WATCH");
    Verb* look = new Verb(2, "LOOK", lookSynonyms);
    allowedVerbs.push_back(look);
    
    std::vector<std::string> useSynonyms;
    lookSynonyms.push_back("UTILIZE");
    lookSynonyms.push_back("ACTIVATE");
    Verb* use = new Verb(3, "USE", useSynonyms);
    allowedVerbs.push_back(use);

    std::vector<std::string> exploreSynonyms;
    Verb* explore = new Verb(4, "EXPLORE", exploreSynonyms);
    allowedVerbs.push_back(explore);

    std::vector<std::string> dropSynonyms;
    Verb* drop = new Verb(5, "DROP", dropSynonyms);
    allowedVerbs.push_back(drop);
}

Utils::~Utils() {}

Verb* Utils::getVerb(const std::vector<std::string> playerCommandTokenized) {
    for (size_t i = 0; i < playerCommandTokenized.size(); i++) {
        for (size_t j = 0; j < allowedVerbs.size(); j++) {
            if (compareStringsIgnoreCase(allowedVerbs.at(j)->name, playerCommandTokenized.at(i))) {
                return allowedVerbs.at(j);
            }
            else {
                for (size_t k = 0; k < allowedVerbs.at(j)->synonyms.size(); k++) {
                    if (allowedVerbs.at(j)->synonyms.at(k).compare(playerCommandTokenized.at(i)) == 0) {
                        return allowedVerbs.at(j);
                    }
                }
            }
        }
    }
    return nullptr;
}

std::vector<std::string> Utils::tokenize(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> tokenized;
    std::string word;

    while (iss >> word) {
        tokenized.push_back(word);
    }

    return tokenized;
}

bool Utils::contains(const std::vector<std::string> tokens, const std::string token) {
    return true;
}

bool Utils::compareStringsIgnoreCase(const std::string& str1, const std::string& str2)
{
    if (str1.length() != str2.length())
        return false;

    for (size_t i = 0; i < str1.length(); ++i) {
        if (tolower(str1[i]) != tolower(str2[i]))
            return false;
    }

    return true;
}

Room* Utils::getGoCommandDestination(const std::vector<std::string>& playerCommandTokenized, const Room* currentRoom) {
    for (size_t i = 0; i < playerCommandTokenized.size(); i++) {
        for (size_t j = 0; j < currentRoom->exits.size(); j++) {
            if (compareStringsIgnoreCase(playerCommandTokenized.at(i), currentRoom->exits.at(j)->destination->name)
                || compareStringsIgnoreCase(playerCommandTokenized.at(i), currentRoom->exits.at(j)->direction)) {
                return currentRoom->exits.at(j)->destination;
            }
        }
    }
    return nullptr;
}

Entity* Utils::getGenericDirectObject(const std::vector<std::string>& playerCommandTokenized, const Room* currentRoom, const Creature* creature) {
    for (size_t i = 0; i < playerCommandTokenized.size(); i++) {
        for (size_t j = 0; j < creature->inventory.size(); j++) {
            if (compareStringsIgnoreCase(playerCommandTokenized.at(i), creature->inventory.at(j)->name)) {
                return creature->inventory.at(j);
            }
        }
        for (size_t j = 0; j < currentRoom->items.size(); j++) {
            if (compareStringsIgnoreCase(playerCommandTokenized.at(i), currentRoom->items.at(j)->name)) {
                return currentRoom->items.at(j);
            }
        }
        for (size_t j = 0; j < currentRoom->exits.size(); j++) {
            if (compareStringsIgnoreCase(playerCommandTokenized.at(i), currentRoom->exits.at(j)->destination->name)
                || compareStringsIgnoreCase(playerCommandTokenized.at(i), currentRoom->exits.at(j)->direction)) {
                return currentRoom->exits.at(j);
            }
        }
    }
    return nullptr;
}

Entity* Utils::getGenericIndirectObject(const std::vector<std::string>& playerCommandTokenized, const Room* currentRoom, const Creature* creature) {
    std::vector<std::string> res;
    for (size_t i = 0; i < playerCommandTokenized.size(); i++) {
        if (i > 0 && (compareStringsIgnoreCase(playerCommandTokenized.at(i-1), "with")
            || compareStringsIgnoreCase(playerCommandTokenized.at(i-1), "on"))) {
            res.push_back(playerCommandTokenized.at(i));
        }
    }
    return getGenericDirectObject(res, currentRoom, creature);
}

void Utils::commandNotUnderstood() {
    std::cout << "Sorry, I didn't understand your command" << std::endl;
}

void Utils::cannotUseItem(const Entity* itemUsed, const Entity* usedOn) {
    std::cout << "You cannot use " << itemUsed->name << " on " << usedOn->name << std::endl;
}

void Utils::removeItemFromRoom(const Item* item, Room* room) {
    for (size_t i = 0; i < room->items.size(); i++) {
        if (compareStringsIgnoreCase(room->items.at(i)->name, item->name)) {
            room->items.erase(room->items.begin() + i);
            return;
        }
    }
}

void Utils::removeItemFromInventory(Item* item, Creature* creature) {
    for (size_t i = 0; i < creature->inventory.size(); i++) {
        if (compareStringsIgnoreCase(creature->inventory.at(i)->name, item->name)) {
            creature->inventory.erase(creature->inventory.begin() + i);
        }
    }
}

Item* Utils::getItemFromInventory(Entity* item, Creature* creature) {
    for (size_t i = 0; i < creature->inventory.size(); i++) {
        if (compareStringsIgnoreCase(creature->inventory.at(i)->name, item->name)) {
            return creature->inventory.at(i);
        }
    }
    return nullptr;
}