#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Verb;
class Room;
class Entity;

class Utils {
public:
	std::vector<Verb*> allowedVerbs;

	Utils();
	~Utils();
	Verb* getVerb(std::vector<std::string> playerCommandTokenized);
	static std::vector<std::string> tokenize(const std::string& input);
	static bool contains(const std::vector<std::string> tokens, std::string token);
	static bool compareStringsIgnoreCase(const std::string& str1, const std::string& str2);
	static Room* getGoCommandDestination(const std::vector<std::string>& playerCommandTokenized, const Room* currentRoom);
	static Entity* getGenericDirectObject(const std::vector<std::string>& playerCommandTokenized, const Room* currentRoom);
	static Entity* getGenericIndirectObject(const std::vector<std::string>& playerCommandTokenized, const Room* currentRoom);
	static void commandNotUnderstood();
};