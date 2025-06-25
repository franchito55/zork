#include "verb.h"

Verb::Verb(int id, const std::string name, const std::vector<std::string> synonyms, bool needsIndirectObject) {
	this->id = id;
	this->name = name;
	this->synonyms = synonyms;
	this->needsIndirectObject = needsIndirectObject;
}

Verb::~Verb() {}