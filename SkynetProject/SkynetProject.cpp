// SkynetProject.cpp : Defines the entry point for the console application.
//

//Include all libraries needed
#include "stdafx.h"
#include <iostream>
//Random Number Seeding
#include <ctime>
using std::cout;
using std::endl;

int main()
{	//start randomly generating
	cout << "Generate Random Enemy Location on 8x8 grid..." << endl;
	srand(time(0));

	//define the high and low number and come up with a random location for the missle
	int searchGridHighNumber = 64;
	int searchGridLowNumber = 1;
	int enemyLocation = rand() % searchGridHighNumber + searchGridLowNumber;
	
	//Print enemy location and some stuff about the program
	cout << "The Missle is in location #" << enemyLocation
		<< " on and 8x8 grid with sectors 1-64" << endl;
	cout << "US Anti-Missle Protection Program Initializing software... " << endl;

	//define number of predictions
	int targetLocationPredictionCounter = 0;

	// set if the target is found
	bool targetFound = false;

	//Run the program while the enemy is not found
	while(targetFound == false)
	{

		//come up with a random guess for the location
		int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		targetLocationPredictionCounter++;

		//print the guess number 
		cout << "===========================================================" << endl;
		cout << "US Anti-Missle Protection Program sending out ping #" << targetLocationPredictionCounter << endl;

		//If the guess is higher remove all numbers plus the guessed number and reguess and adds one to the guesses
		if (targetLocationPrediction > enemyLocation) {
			searchGridHighNumber = targetLocationPrediction - 1;
			cout << "The target location predeiction of " << targetLocationPrediction << " was higher then the actual location\n";
			cout << "The program is now searching in areas below  = " << searchGridHighNumber << endl;
		}
		//If the guess is lower remove all numbers plus the guessed number and reguess and adds one to the guesses
		else if (targetLocationPrediction < enemyLocation) {
			searchGridLowNumber = targetLocationPrediction + 1;
			cout << "The target location predeiction of " << targetLocationPrediction << " was lower then the actual location\n";
			cout << "The program is now searching in areas above = " << searchGridLowNumber << endl;
		}
		//if the guess is correct print the location and how many tries it took
		else if (targetLocationPrediction == enemyLocation)
		{
			cout << "Missle was hiding at location #" << enemyLocation << endl;
			cout << "Target was found at location #" << targetLocationPrediction << endl;
			cout << "US Anti-Missle Protection Program took " << targetLocationPredictionCounter << " tries to find the Missle." << endl;
			targetFound = true;
		}
		else {
			//If something messes up it ends the program
			cout << "Program malfuntion!!!!!" << endl;
			cout << "Well, someones not going to enjoy that missle." << endl;
			targetFound = true;
		}
	}
	system("pause");
    return 0;
}

