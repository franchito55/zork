#pragma once
#include <string>
#include <vector>

class Verb {
public:
	// numerical id to use switch statement
	int id;
	std::string name;
	std::vector<std::string> synonyms;
	// Whether the verb needs an indirect object 
	bool needsIndirectObject;
	Verb(int id, std::string name, std::vector<std::string> synonyms, bool transitive);
	~Verb();
};