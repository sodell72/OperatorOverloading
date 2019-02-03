#include "Room.h"
#include <iostream>
#include <math.h>
using namespace std;



int main(int argc, char * argv[]) {

	Room room1;
	Room room2;
	Room* fancyRoom = new Room("Fancy");
	Room uglyRoom("Ugly", 8800.50);
	Room defaultRoom("Default", 2002);

	// test default constructor and static variable
	cout << "room1's name is: " + room1.getName() << endl;
	cout << "room2's name is: " + room2.getName() << endl;
	cout << endl;

	// test parameter constructor with default values using pointer construction
	cout << "fancyRoom's name is: " + fancyRoom->getName() << endl;
	cout << "fancyRoom's cost is: $";
	printf("%.2f", fancyRoom->getCost());
	cout << endl;
	cout << endl;

	// test parameter constructor with non default values
	cout << "uglyRoom's name is: " + uglyRoom.getName() << endl;
	cout << "uglyRoom's cost is: $" << uglyRoom.getCost() << endl;
	cout << endl;

	// test default room with defalt parameter overwritten
	cout << "defaultRoom's cost is: $" << defaultRoom.getCost() << endl;
	cout << endl;

	// test static variable still working properly
	Room room3;
	cout << "room3's name is: " << room3.getName() << endl;
	cout << endl;

	// test + operator
	Room addFancyDefault = uglyRoom + defaultRoom;
	cout << "The cost of ugly + default is " << uglyRoom.getCost() << " + " << defaultRoom.getCost() << ": " 
		<< addFancyDefault.getCost() << endl;
	cout << "The cost of uglyRoom is still: " << uglyRoom.getCost() << endl;
	cout << "The cost of defaultRoom is still: " << defaultRoom.getCost() << endl;
	cout << endl;

	// test += operator
	uglyRoom += defaultRoom;
	cout << "The value of ugly after ugly += default is: " << uglyRoom.getCost() << endl;
	cout << "The cost of defaultRoom is still: " << defaultRoom.getCost() << endl;
	cout << endl;

	// test == operator
	Room& equalRoom = room1;
	cout << "equalRoom is equal to room1: " << (room1 == equalRoom) << endl;
	cout << "equalRoom is not equal to room2: " << (room2 == equalRoom) << endl;
	cout << "equalRoom is not equal to fancyRoom: " << (*fancyRoom == equalRoom) << endl;
	cout << endl;

	// test -- operator
	Room cheapRoom("Cheap", 500);
	uglyRoom--;
	cout << "UglyRoom now costs: " << uglyRoom.getCost() << endl;
	try {
		cheapRoom--;
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	cout << endl;

	// test destructor
	cout << "calling fancyRoom's function before destructor called: " + fancyRoom->getName() << endl;
	delete fancyRoom;
	cout << "trying to call fancyRoom's function after 'delete fancyRoom' was called: ";
	try {
		fancyRoom->getName();
	}
	catch (exception e) {
		cerr << "exception was caught, can't use fancyRoom anymore because it has been deleted" << endl;
	}
	

	cin.get();
	return 0;
}