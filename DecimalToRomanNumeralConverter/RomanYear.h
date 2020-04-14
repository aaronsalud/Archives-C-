#ifndef __ROMANYEAR_H__
#define __ROMANYEAR_H__

#include <string>
#include <map>

class RomanYear
{
	std::string year;
	std::string roman_year;
	std::map<int, std::string> romanNums;

	void initializeRomanNums();
	void calculateRomanYear();
	void generateRomanDigits( int, int, int, int);
	
	public:
		RomanYear(std::string&);
		const std::string& getRomanYear();
};
#endif