#include "world.h"
#include "room.h"
#include "exit.h"
#include "key.h"
#include "safe.h"

World::World() {
	Room* forest = new Room("Forest", "The forest in which the adventure begins.", false);
	this->AddRoom(forest);
	this->currentRoom = forest;

	Room* shack = new Room("Shack", "The shack of an unknown inhabitant.", false);
	this->AddRoom(shack);
	Exit* exitForestToShack = new Exit("Suspicious space between bushes", "A path which seems man-made between some bushes, probably hidden on purpose.", "West", forest, shack);
	Exit* exitShackToForest = new Exit("Wooden door", "A wooden door, with a few deep scratches on it.", "East", shack, forest);
	forest->AddExit(exitForestToShack);
	shack->AddExit(exitShackToForest);

	Room* shackBedroom = new Room("Bedroom", "A run-through bedroom, with stuff all around the floor.", false);
	this->AddRoom(shackBedroom);
	Exit* exitShackToShackBedroom = new Exit("A wooden door", "A normal wooden door.", "South", shack, shackBedroom);
	shack->AddExit(exitShackToShackBedroom);
	Exit* exitShackBedroomToShack = new Exit("A wooden door", "A normal wooden door.", "North", shackBedroom, shack);
	shackBedroom->AddExit(exitShackBedroomToShack);

	Room* shackBathroom = new Room("Bathroom", "A small bathroom with dirty walls which once were of clean white tiles.", true);
	this->AddRoom(shackBathroom);
	Exit* exitShackToShackBathroom = new Exit("A half-open metal door", "A metal door, which is half open, and has a sign on it that says 'WC'.", "North", shack, shackBathroom);
	shack->AddExit(exitShackToShackBathroom);
	Exit* exitShackBathroomToShack = new Exit("A half-open metal door", "A metal door, which is half open. It leads back to the shack'.", "South", shackBathroom, shack);
	shackBathroom->AddExit(exitShackBathroomToShack);

	Room* school = new Room("School", "A small school, which looks like it has been abandoned for a few years. Mostly built of concrete.", true);
	this->AddRoom(school);
	Exit* exitForestToSchool = new Exit("A clear gravel path", "A path made of gravel, with some trees and some small street lights around.", "East", forest, school);
	forest->AddExit(exitForestToSchool);
	Exit* exitSchoolToForest = new Exit("A clear gravel path", "A path made of gravel which seems to lead to a forest.", "West", school, forest);
	school->AddExit(exitSchoolToForest);

	Room* schoolHallway = new Room("Hallway", "An empty hallway, seems to lead to where the students took their classes.", false);
	this->AddRoom(schoolHallway);
	Exit* exitSchoolToSchoolHallway = new Exit("A glass door", "A glass door which seems to lead to a hallway.", "North", school, schoolHallway);
	school->AddExit(exitSchoolToSchoolHallway);
	Exit* exitSchoolHallwayToSchool = new Exit("A glass door", "A glass door which seems to lead to the school reception.", "South", schoolHallway, school);
	schoolHallway->AddExit(exitSchoolHallwayToSchool);

	Room* schoolClassroom = new Room("Classroom", "Just an empty classroom.", false);
	this->AddRoom(schoolClassroom);
	Exit* exitSchoolHallwayToClassroom = new Exit("A wooden door", "A wooden door which seems to lead to a classroom. It has a sign on it which says '1A'", "West", schoolHallway, schoolClassroom);
	schoolHallway->AddExit(exitSchoolHallwayToClassroom);
	Exit* exitClassroomAToSchoolHallway = new Exit("A wooden door", "A wooden door which leads to the corridor you just came from.", "East", schoolClassroom, schoolHallway);
	schoolClassroom->AddExit(exitClassroomAToSchoolHallway);
	
	Room* laboratory = new Room("Laboratory", "Just an empty laboratory with some desks and some lab equipment.", false);
	this->AddRoom(laboratory);
	Exit* exitSchoolHallwayToLaboratory = new Exit("A wooden door", "A wooden door which seems to lead to what looks like a laboratory. It has a sign on it which says 'Chemistry'", "North", schoolHallway, laboratory);
	schoolHallway->AddExit(exitSchoolHallwayToLaboratory);
	Exit* exitLaboratoryToSchoolHallway = new Exit("A wooden door", "A wooden door which leads to the corridor you just came from.", "East", laboratory, schoolHallway);
	laboratory->AddExit(exitLaboratoryToSchoolHallway);

	Room* schoolBathroom = new Room("Bathroom", "A school bathroom with several stalls", false);
	this->AddRoom(schoolBathroom);
	Exit* exitSchoolHallwayToSchoolBathroom = new Exit("A blue plastic door", "A blue plastic door with a sign that says 'WC' on it.", "East", schoolHallway, schoolBathroom);
	schoolHallway->AddExit(exitSchoolHallwayToSchoolBathroom);
	Exit* exitSchoolBathroomToSchoolHallway = new Exit("A blue plastic door", "A blue plastic door with a sign that says 'WC' on it. It leads to the corridor", "West", schoolBathroom, schoolHallway);
	schoolBathroom->AddExit(exitSchoolBathroomToSchoolHallway);

	Room* principalsOffice = new Room("Office", "An empty office except for a desk in the middle of it. It seems it belonged to the principal.", true);
	this->AddRoom(principalsOffice);
	Exit* exitSchoolToPrincipalsOffice = new Exit("A wide double wooden door", "A set of two fancy wooden doors side by side. It has a sign on it that says 'Principal Walter'.", "East", school, principalsOffice);
	school->AddExit(exitSchoolToPrincipalsOffice);
	Exit* exitPrincipalsOfficeToSchool = new Exit("A wide double wooden door", "A set of two fancy wooden doors side by side. They lead to the school's reception.", "West", principalsOffice, school);
	principalsOffice->AddExit(exitPrincipalsOfficeToSchool);

	Key* woodenKey = new Key("Wooden_key", "A wooden key with the letters 'WC' etched on it");
	woodenKey->opens = shackBathroom;
	woodenKey->location = shackBedroom;
	shackBedroom->AddItem(woodenKey);

	Key* schoolKey = new Key("Aluminum_key", "A key made of aluminum with an 'S' written on it.");
	schoolKey->opens = school;
	schoolKey->location = shackBathroom;
	shackBathroom->AddItem(schoolKey);

	Key* principalsOfficeKey = new Key("Black_key", "A black plastic key with an uppercase W etched on it.");
	principalsOfficeKey->location = laboratory;
	principalsOfficeKey->opens = principalsOffice;
	laboratory->AddItem(principalsOfficeKey);

	Safe* safe = new Safe("Safe", "A titanium safe. It probably contains what you're looking for...");
	principalsOffice->AddItem(safe);

	Key* safeCode = new Key("Safe_code", "A small piece of paper with 4 numbers written on it.");
	safeCode->location = schoolBathroom;
	safeCode->opens = safe;
	schoolBathroom->AddItem(safeCode);
}

void World::AddRoom(Room* room) {
	rooms.push_back(room);
}

World::~World() {}