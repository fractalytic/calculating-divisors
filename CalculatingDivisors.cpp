// CalculatingDivisors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//Calculating Divisors
//by Shane
//
//The code requires an input integer less than the arrSize variable
//and will then return all divisors and work out if the number is perfect, abundant or deficient
//
//Feel free to look at this code and learn but please don't reuse it without my permission
//
//This code works best using a proper C compiler rather than the SoloLearn testing environment
//due to needing input from the user
//
//
//original code: 2nd April 2017
//update: no further updates yet
//

#include <iostream>
#include <cmath>
#include <ctime>
#include <sstream>
using namespace std;

int main()
{
	//declare the variables
	const int arrSize = 100001;   //this is included as a constant so that the upper bound can be changed easily
	int testValue = 0;
	string inputStr = "";
	bool divisorArray[arrSize];    //this isn't actually necessary but is kept in case anything extra will be added in an update
	int i = 0, j = 0;
	int divisorTotal = 0, divisorCount = 0;
	string divisorType = "perfect";
	bool loopContinue = true;
	bool validInput = false;
	string loopAnswer = "";
	clock_t startTime, currentTime;
	double elapsedSeconds;


	while (loopContinue == true) {
		//initialise the array
		for (i = 0; i < arrSize; i++) {
			divisorArray[i] = false;
		}

		//get input from the user
		validInput = false;
		while (validInput == false) {
			cout << "Please enter a number from 2 to " << arrSize - 1 << " > ";
			getline(cin, inputStr);

			//try converting to integer 
			stringstream myStream(inputStr);
			if (myStream >> testValue) {
				if (testValue > 1 && testValue < arrSize) {
					validInput = true;
				}
				else {
					cout << "That value isn't valid, please try again" << endl << endl;
				}
			}
			else {
				cout << "That value isn't valid, please try again" << endl << endl;
			}
		}

		startTime = clock();

		//Work out the divisors of the testValue (excluding itself) and output to screen
		cout << "The divisors of " << testValue << " excluding itself: " << endl;
		divisorCount = 0;
		divisorTotal = 0;
		for (i = 1; i < testValue; i++) {
			if (testValue % i == 0){
				divisorArray[i] = true;
				cout << i << " ";
				divisorCount++;
				divisorTotal += i;
			}
		}
		cout << endl << "The number of divisors is: " << divisorCount << " and the sum is: " << divisorTotal << endl;

		//what kind of number if this?
		if (divisorTotal < testValue) {
			divisorType = "This makes it a deficient number";
		}
		else
		{
			if (divisorTotal == testValue) {
				divisorType = "This makes it a perfect number";
			}
			else {
				divisorType = "This makes it an abundant number";
			}
		}

		cout << divisorType << endl;


		currentTime = clock();
		elapsedSeconds = ((currentTime - startTime) / (CLOCKS_PER_SEC / 1.0));
		cout.precision(4);
		cout << "This took: " << fixed << elapsedSeconds << " seconds to run" << endl << endl;

		cout << "Do you want another go (Y/N)? ";
		getline(cin, loopAnswer);
		if (loopAnswer == "y" || loopAnswer == "Y") {
			loopContinue = true;
			cout << endl;
		}
		else {
			loopContinue = false;
		}

	}

	return 0;
}


