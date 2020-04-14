//
//  RomanYear.cpp
//  RomanNumeralConversion Program
//
//  Created by Aaron Salud on 2015-06-12.
//  Copyright (c) 2015 Aaron Salud. All rights reserved.
//

#include "RomanYear.h"

// RomanYear constructor
RomanYear::RomanYear(std::string& yr)
{
	initializeRomanNums();	// Initialize a map of roman numbers
	this->year = yr;		// Assign user input to a string variable
	calculateRomanYear();   // calculate for the roman year
}

// initializeRomanNums Function
void RomanYear::initializeRomanNums()
{
	this->romanNums[1] = "I";			// Assign map values
	this->romanNums[5] = "V";
	this->romanNums[10] = "X";
	this->romanNums[50] = "L";
	this->romanNums[100] = "C";
	this->romanNums[500] = "D";
	this->romanNums[1000] = "M";
}

// calculateRomanYear
void RomanYear::calculateRomanYear()
{
	switch (this->year.length())					// determine length of the year (maximum to 4 characters)
	{
	case 4:
		generateRomanDigits(0, 1000, 1000, 1000);	// Analyze first digit
		generateRomanDigits(1, 1000, 100, 500);		// Analyze second digit
		generateRomanDigits(2, 100, 10, 50);		// Analyze third digit
		generateRomanDigits(3, 10, 1, 5);			// Analyze fourth digit
		break;
	case 3:
		generateRomanDigits(0, 1000, 100, 500);		// Analyze first digit
		generateRomanDigits(1, 100, 10, 50);		// Analyze second digit
		generateRomanDigits(2, 10, 1, 5);			// Analyze third digit
		break;
	case 2:

		generateRomanDigits(0, 100, 10, 50);		// Analyze first digit
		generateRomanDigits(1, 10, 1, 5);			// Analyze second digit
		break;
	case 1:
		generateRomanDigits(0, 10, 1, 5);			// Analyze first digit
		break;
	}
}

// generateRomanDigits Function
void RomanYear::generateRomanDigits(int idx, int max, int min, int mid)
{
	if (this->year[idx] == '9')		// Concatenate according to the min and max roman digit based on the decimal digit position
	{
		this->roman_year += this->romanNums[min] + this->romanNums[max];
	}

	else if (this->year[idx] == '4')	// Concatenate according to the min and mid roman digit based on the decimal digit position
	{
		this->roman_year += this->romanNums[min] + this->romanNums[mid];
	}

	else if (this->year[idx] >= '5')	// Concatenate roman digit based with decimal digits greater than or equal to 5
	{
		for (int i = 5; i <= this->year[idx] - '0'; ++i)
		{
			i == 5 ? this->roman_year += this->romanNums[mid] : this->roman_year += this->romanNums[min];
		}
	}
	else if (this->year[idx] != '0')	// Concatenate roman figit based on decimal digits 4 and below except 0
	{
		for (int i = 0; i < this->year[idx] - '0'; ++i)
		{
			this->roman_year += this->romanNums[min];
		}
	}
}

//getRomanYear Function
const std::string& RomanYear::getRomanYear()
{
	return this->roman_year;	// return roman_year value as a constant string reference
}