#pragma once
#include<string>

class Room {

private:
	std::string name;
	double cost;
	static int unNamedRooms;
	static const int minCost = 1000;

public:
	Room();
	Room(std::string, double = 0);
	~Room();

	std::string getName();
	double getCost();

	Room operator+(const Room &rm) const;
	Room operator+=(const Room &rm);
	bool operator==(const Room &rm) const;
	Room operator--(int);

};