#include "safe.h"
#include "key.h"
#include <iostream>

Safe::Safe(const std::string name, const std::string description) : Item(name, description) {}

Safe::~Safe() {}

int Safe::useItem(Item* item) {
	Key* key = dynamic_cast<Key*>(item);
	if (key) {
		if (this == key->opens) {
			std::cout << "Congratulations! You have opened the safe with the scripture to the school. You can now reopen it under your rule. It is what you always wanted..." << std::endl;
			return 2;
		}
		else {
			std::cout << "You cannot open the safe with a key" << std::endl;
		}
	}
	return 1;
}