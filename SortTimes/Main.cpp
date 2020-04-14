#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool compare(const std::string&, const std::string&);
int main(int argc, char** argv)
{
	std::ifstream file("TimesFile.txt");
	std::vector<std::string> times;

	if (!file.is_open())
	{
		std::cout << "File not opened" << std::endl;
	}

	/*
	else
	{
		std::string line;
		
		

		while (std::getline(file, line, ','))
		{
			times.push_back(line);
		}

		for (std::vector<std::string>::iterator i = times.begin(); i != times.end(); i++)
		{
			std::cout << *i << std::endl;
		}
	
	}
	*/
	else
	{
		char buff[80];

		while (!file.eof())
		{
		
			file.getline(buff, sizeof(buff), '\n');
			
			char* begin, *comma;
			begin = comma = buff;

			while (comma < buff + strlen(buff))
	
				comma = std::find(comma, buff+strlen(buff), ',');

				int hours = atoi(begin);
				char* colon = std::find(begin, comma, ':');

				if (colon != comma)
				{
					char finaltime[6];
					int minutes = atoi(colon + 1);
					
					sprintf_s(finaltime, "%02d:%02d", hours, minutes);
					std::cout << finaltime << std::endl;
					times.push_back(finaltime);
				}
				begin = comma += 1;
			
			}
		
		}
	}
	std::cout << std::endl;

	std::sort(times.begin(), times.end(), compare);

	for (std::vector<std::string>::iterator i = times.begin(); i != times.end(); i++)
	{
		std::cout << *i << std::endl;
	}

	return 0;
}

bool compare(const std::string& a, const std::string& b)
{
	return (a.compare(b) == -1);
}