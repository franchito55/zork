#include "entity.h"

Entity::Entity(const char* name, const char* description)
    : name(name), description(description), entityType(EntityType::ITEM) {}

Entity::~Entity() {}