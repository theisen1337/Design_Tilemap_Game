#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>

class app_settings
{
public:
	app_settings();
	~app_settings();

	//struct key_value {
	//	std::string name;
	//	std::string value;
	//};

	void load_settings(std::string filepath);

	//std::vector<key_value> get_settings();
	template <class T>
	T get_value(std::string name);

	// IN APP SETTINGS
	//int map_scroll_speed = 1;

private:
	// LOAD SETTINGS
	bool set_parameters(std::string name, std::string value);

	std::string settings_file_str = "resources\\settings.config";

	std::vector<std::string> known_names = { "version", "TILE_H","TILE_W","CHUNK_W","CHUNK_H","WIN_H","WIN_W","SEED" };
	//std::vector<key_value> settings;

	std::map<std::string, int> int_map;
	std::map<std::string, float> float_map;
	std::map<std::string, std::string> str_map;


	inline bool _is_float(std::string str) {
		/*

			Check if string is float

		*/
		std::istringstream iss(str);
		float f;
		iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
		// Check the entire string was consumed and if either failbit or badbit is set
		return iss.eof() && !iss.fail();
	}

	inline bool _is_integer(const std::string& str)
	{
		/*

			Check if string is int.

		*/
		if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+'))) return false;

		char* p;
		strtol(str.c_str(), &p, 10);

		return (*p == 0);
	}

	/*inline bool _file_exist(const std::string& name) {
		if (FILE * file = fopen(name.c_str(), "r")) {
			fclose(file);
			return true;
		}
		else {
			return false;
		}
	}*/

	inline bool _file_exist(const char* fileName)
	{
		std::ifstream infile(fileName);
		return infile.good();
	}

};

