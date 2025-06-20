#include "item.h"

Item::Item(const char* name, const char* description) : Entity(name, description) {
	entityType = EntityType::ITEM;
}