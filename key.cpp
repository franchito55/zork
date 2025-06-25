#include "key.h"
#include "utils.h"

Key::Key(const std::string name, const std::string description) : Item(name, description) {
	opens = nullptr;
}

Key::~Key() {}