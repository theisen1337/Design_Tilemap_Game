#include "app_settings.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

/*
	File is not cross-platform when it comes to file/folder structures.
	Qt could be used for better cross platform abilities.
*/

app_settings::app_settings()
{
	
	if (_file_exist(this->settings_file_str.c_str()))
	{
		// file already exist.
		load_settings(this->settings_file_str);
	}
	else
	{
		// file does NOT exist, and needs to be created.
		std::cout << "Not implemented, need to implement creating default settings.\n";
		exit(1);
	}
}


app_settings::~app_settings()
{
}


void app_settings::load_settings(std::string filepath)
{
	/*
	
		Loading settings file.
	
	*/
	std::string line;
	std::ifstream infile(filepath);
	if (infile.is_open())
	{
		std::cout << "opened " << filepath << std::endl;
		while (std::getline(infile, line))
		{
			std::cout << "loading: " << line;
			std::string value = line.substr(line.find_first_of('=') + 1, line.length());
			std::string name = line.substr(0, line.find_first_of('='));
			if (set_parameters(name, value))
			{
				std::cout << name << "  ..success!" << std::endl;
			}
			else
			{
				std::cout << name << " ..not value, skipping." << std::endl;
			}
		}
		//closing file
		infile.close();
	}
	else
	{
		std::cout << "error opening " << filepath << std::endl;
		//closing file
		infile.close();
	}
}


template <class T>
T app_settings::get_value(std::string name)
{
	/*
	
		Searches for value in the 3 different maps.
		map.find() is log time complexity.
		exit program if app calls a setting not loaded into the aoo_settings.
	
	*/
	if (this->int_map.find(name) != this->int_map.end())
		return this->int_map.find(name)->second;

	if (this->str_map.find(name) != this->str_map.end())
		return this->str_map.find(name)->second;

	if (this->float_map.find(name) != this->float_map.end())
		return this->float_map.find(name)->second;

	std::cout << "Error getting setting.\n";
	exit(1);
}


bool app_settings::set_parameters(std::string name, std::string value)
{
	/*
	
		Checks type of data, float, int, string, and put into following map,
		this is extra work to not create a std::map<std::string, T>
	
	*/
	for (int i = 0; i < this->known_names.size(); i++)
	{
		if (name == this->known_names.at(i))
		{
			if (_is_integer(value))
			{
				this->int_map[name] = std::stoi(value);
			}
			else if (_is_float(value))
			{
				this->float_map[name] = std::atof(value.c_str());
			}
			else
			{
				this->str_map[name] = value;
			}

			return true;
		}
	}
	return false;
}
