//Alexander Maiden
//CS1B 
//11-6-19

#include "battleship.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main()
{	
	//Guess Counter
	int guess = 0;
	cout << "BATTLESHIP" << endl;
	cout << "By: Alexander Maiden" << endl;
	cout << "Guess ship coordinates (1-6 = x, a-f = y) in an attempt to sink an entire fleet!" << endl;
	srand(time(nullptr));
	Fleet myFleet;
	//Deploying Fleet.
	cout << "Deploying Fleet..." << endl;
	myFleet.deployFleet();
	cout << "Fleet Deployed." << endl;
	myFleet.printFleet();
	do {
		//User Target.
		Location userTarget;
		userTarget.fire();
		//Checking to see if User Target hits.
		if (myFleet.isHitNSink(userTarget) == true)
			cout << "Hit! You sunk a battleship!" << endl;
		else
			cout << "Miss! There is no ship at ";
		userTarget.print();
		++guess;
	} while (myFleet.operational());
	cout << endl;
	cout << "You won! It took you " << guess << " " << "guesses!";
}


