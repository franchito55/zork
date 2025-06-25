#include "world.h"
#include "room.h"
#include "exit.h"

World::World() {
	Room* forest = new Room("Forest", "The forest in which the adventure begins");
	this->AddRoom(forest);
	this->currentRoom = forest;

	Room* shack = new Room("Shack", "The shack of an unknown inhabitant");
	this->AddRoom(shack);
	Exit* exitForestToShack = new Exit("Suspicious space between bushes", "A path which seems man-made between some bushes, probably hidden on purpose.", "West", forest, shack);
	Exit* exitShackToForest = new Exit("Wooden door", "A wooden door, with a few deep scratches on it.", "East", shack, forest);
	forest->AddExit(exitForestToShack);
	shack->AddExit(exitShackToForest);

	Room* shackBedroom = new Room("Bedroom", "A run-through bedroom, with stuff all around the floor.");
	this->AddRoom(shackBedroom);
	Exit* exitShackToShackBedroom = new Exit("A wooden door", "A normal wooden door.", "South", shack, shackBedroom);
	shack->AddExit(exitShackToShackBedroom);

	Room* shackBathroom = new Room("Bathroom", "A small bathroom with dirty walls which once were of clean white tiles.");
	this->AddRoom(shackBathroom);
	Exit* exitShackToShackBathroom = new Exit("A half-open metal door", "A metal door, which is half open, and has a sign on it that says 'WC'.", "North", shack, shackBathroom);
	shack->AddExit(exitShackToShackBathroom);

	Room* school = new Room("Abandoned school", "A small school, which looks like it has been abandoned for a few years. Mostly built of concrete.");
	this->AddRoom(school);
	Exit* exitForestToSchool = new Exit("A clear gravel path", "A path made of gravel, with some trees and some small street lights around.", "East", forest, school);
	forest->AddExit(exitForestToSchool);
	Exit* exitSchoolToForest = new Exit("A clear gravel path", "A path made of gravel which seems to lead to a forest.", "West", school, forest);
	school->AddExit(exitSchoolToForest);

	Room* schoolHallway = new Room("An empty hallway", "An empty hallway, seems to lead to where the students took their classes.");
	this->AddRoom(schoolHallway);
	Exit* exitSchoolToSchoolHallway = new Exit("A glass door", "A glass door which seems to lead to a hallway.", "North", school, schoolHallway);
	school->AddExit(exitSchoolToSchoolHallway);
	Exit* exitSchoolHallwayToSchool = new Exit("A glass door", "A glass door which seems to lead to the school reception.", "South", schoolHallway, school);
	schoolHallway->AddExit(exitSchoolHallwayToSchool);

	Room* schoolClassroomA = new Room("A classroom", "Just an empty classroom.");
	this->AddRoom(schoolClassroomA);
	Exit* exitSchoolHallwayToClassroomA = new Exit("A wooden door", "A wooden door which seems to lead to a classroom. It has a sign on it which says 'A'", "West", schoolHallway, schoolClassroomA);
	schoolHallway->AddExit(exitSchoolHallwayToClassroomA);
	Exit* exitClassroomAToSchoolHallway = new Exit("A wooden door", "A wooden door which leads to the corridor you just came from.", "East", schoolClassroomA, schoolHallway);
	schoolClassroomA->AddExit(exitClassroomAToSchoolHallway);
	
	Room* schoolClassroomB = new Room("Another classroom", "Just an empty classroom with some desks.");
	this->AddRoom(schoolClassroomB);
	Exit* exitSchoolHallwayToClassroomB = new Exit("A wooden door", "A wooden door which seems to lead to a classroom. It has a sign on it which says 'B'", "North", schoolHallway, schoolClassroomB);
	schoolHallway->AddExit(exitSchoolHallwayToClassroomA);
	Exit* exitClassroomBToSchoolHallway = new Exit("A wooden door", "A wooden door which leads to the corridor you just came from.", "East", schoolClassroomB, schoolHallway);
	schoolClassroomB->AddExit(exitClassroomBToSchoolHallway);

	Room* schoolBathroom = new Room("A bathroom", "A school bathroom with several stalls");
	this->AddRoom(schoolBathroom);
	Exit* exitSchoolHallwayToSchoolBathroom = new Exit("A blue plastic door", "A blue plastic door with a sign that says 'WC' on it.", "East", schoolHallway, schoolBathroom);
	schoolHallway->AddExit(exitSchoolHallwayToSchoolBathroom);
	Exit* exitSchoolBathroomToSchoolHallway = new Exit("A blue plastic door", "A blue plastic door with a sign that says 'WC' on it. It leads to the corridor", "West", schoolBathroom, schoolHallway);
	schoolHallway->AddExit(exitSchoolBathroomToSchoolHallway);

	Room* principalsOffice = new Room("An office", "An empty office except for a desk in the middle of it. It seems it belonged to the principal.");
	this->AddRoom(principalsOffice);
	Exit* exitSchoolToPrincipalsOffice = new Exit("A wide double wooden door", "A set of two fancy wooden doors side by side. It has a sign on it that says 'Principal Walter'.", "East", school, principalsOffice);
	school->AddExit(exitSchoolToPrincipalsOffice);
	Exit* exitPrincipalsOfficeToSchool = new Exit("A wide double wooden door", "A set of two fancy wooden doors side by side. They lead to the school's reception.", "West", principalsOffice, school);
	school->AddExit(exitSchoolToPrincipalsOffice);
}

void World::AddRoom(Room* room) {
	rooms.push_back(room);
}

World::~World() {}