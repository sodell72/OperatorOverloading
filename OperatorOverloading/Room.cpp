#include "Room.h"
#include <iostream>

// static variable initialization used for unnamed rooms
int Room::unNamedRooms = 1;


Room::Room() {
	name = "room_" + std::to_string(unNamedRooms);
	unNamedRooms++;
}

Room::Room(std::string name, double cost) {
	Room::name = name;
	Room::cost = cost;
}


Room::~Room() {
	std::cout << "object is being destroyed" << std::endl;
}

std::string Room::getName() {
	return Room::name;
}


double Room::getCost() {
	return Room::cost;
}

Room Room::operator+(const Room & rm) const {
	Room result = *this;
		result.cost += rm.cost;
	return result;
}

Room Room::operator+=(const Room &rm) {
	this->cost += rm.cost;
	return *this;
}

bool Room::operator==(const Room &rm) const {
	if (this != &rm) {
		return false;
	}
	return true;
}

Room Room::operator--(int) {
	if (cost >= 2 * minCost) {
		cost = cost - minCost;
	} else if (cost >= minCost) {
		cost = minCost;
	} else {
		throw "cost less than minCost already, you can't drop the price further.";
	}
	return *this;
}

