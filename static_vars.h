#pragma once
#include "app_settings.h"
class static_variables
{
public:
	static_variables();
	~static_variables();
	static app_settings& get_settings();
private:

};

