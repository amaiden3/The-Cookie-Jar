#include <iostream>
#include <string>
#include "battleship.h"

using namespace std;

// void constructor, assigns -1 to X coord, and * to Y coord 
Location::Location()
{
	x_ = -1;
	y_ = '*';
}
// picks a random location
void Location::pick()
{
	x_ = (rand() % 6 + 1);
	y_ = 'a' + (rand() % 6 + 1);
}
// asks the user to input coordinates of the next shot
void Location::fire()
{
	cout << "Input coordinates of next shot: ";
	cin >> x_ >> y_;
	cout << endl;
}
// prints location in format "a1"
void Location::print() const
{
	cout << x_ << y_ << endl;
}
// predicate returns true if the two locations match
bool compare(const Location& loc1, const Location& loc2) {
	if (loc1.x_ == loc2.x_ && loc1.y_ == loc2.y_) {
		return true;
	}
	else
		return false;
}
// void constructor, sets sunk=false
Ship::Ship()
{
	sunk_ = false;
}
// returns true if this location matches the ships location
bool Ship::match(const Location& loc3) const
{
	return compare(loc3, loc_);
}
// checks to see if the ship is sunk
// sets "sunk" member variable of the ship to true
void Ship::sink()
{
	sunk_ = true;
}
// deploys the ship at the specified location
void Ship::setLocation(const Location& loc)
{
	loc_ = loc;
}
// prints location and status of the ship
void Ship::printShip() const
{
	loc_.print();
	if (sunk_ == true)
		cout << "Sunk" << endl;
	else
		cout << "Not Sunk" << endl;
}
//deploys the ships in random locations
//of the ocean
void Fleet::deployFleet() {
	for (int i = 0; i < fleetSize_; i++) {
		Location randLoc;
		bool validpos = false;
		while (validpos == false) {
			randLoc.pick();
			if (check(randLoc) == -1) {
				ships_[i].setLocation(randLoc);
				validpos = true;
			}
		}
	}
}
// predicate returns true if at least
// one ship in the fleet is not sunk
bool Fleet::operational() const {
	for (int i = 0; i < fleetSize_; i++) {
		if (!ships_[i].isSunk()) {
			return true;
		}
	}
	return false;
}
int Fleet::check(const Location& loc1) const {
	for (int i = 0; i < fleetSize_; i++) {
		if (ships_[i].match(loc1)) {
			return i;
		}
	}
	return -1;
}
// returns true if there was a deployed
// ship at this location (hit) and sinks it
// otherwise returns false (miss)
bool Fleet::isHitNSink(const Location& loc) {
	if (check(loc) != -1) {
		int index = check(loc);
		ships_[index].sink();
		return true;
	}
	else
		return false;
}
//prints out locations of ships in fleet
void Fleet::printFleet() const {
	for (int i = 0; i < fleetSize_; i++) {
		ships_[i].printShip();
	}
}
