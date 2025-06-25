#pragma once
#include <string>
#include <vector>

class Verb {
public:
	// numerical id to use switch statement
	int id;
	std::string name;
	std::vector<std::string> synonyms;
	Verb(int id, std::string name, std::vector<std::string> synonyms);
	~Verb();
};