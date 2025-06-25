#pragma once
#include "item.h"

class Safe : public Item {
public:
	Safe(const std::string name, const std::string description);
	~Safe();
	int useItem(Item* item);
};