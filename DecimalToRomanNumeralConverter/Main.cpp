//
//  main.cpp
//  RomanNumeralConversion Program
//
//  Created by Aaron Salud on 2015-06-12.
//  Copyright (c) 2015 Aaron Salud. All rights reserved.
//

#include <iostream>
#include <string>
#include "RomanYear.h"

void getUserInput(std::string& yr);

//Main Function
int main(int argc, char** argv) {

	std::string year;	// variable declaration

	getUserInput(year);	// call getUserInput

	RomanYear ry(year); // Instantiate a RomanYear instance

	std::cout << "Year: " << year << " is " << ry.getRomanYear() << " in Roman." << std::endl; // Print the results

	return 0;
}

// getUserInput Function
void getUserInput(std::string& yr)
{
	bool done = false;		// Variable declarations
	int attempts = 0;

	do
	{
		if (attempts > 0)	// Print the following statement for multiple attempts
			std::cout << "Invalid input. Try again." << std::endl << std::endl;

		std::cout << "Please enter a year (no greater than 3999) : ";	// Prompt User
		std::getline(std::cin, yr);										// store input as a string

		if (yr.length() <= 4)		// Check the length of the string (limited to 4 characters)
		{
			for (int i = 0; i < yr.length(); ++i)
			{
				done = yr[i] < '0' && yr[i] > '9' ? false : true;	// Validate for numerical characters
			}
		}
		attempts++; // count number of attempts
	} while (yr.length() > 4 || yr[0] >= '4' && yr.length() == 4 || !done); // Loop until input is valid
}