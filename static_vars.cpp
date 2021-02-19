#include "static_vars.h"
#include "app_settings.h"

static app_settings settings = app_settings();




static_variables::static_variables()
{
}

static_variables::~static_variables()
{
}

app_settings& static_variables::get_settings()
{
	return settings;
}
