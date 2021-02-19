#include "debug_stats.h"


debug_stats::debug_stats()
{
}



debug_stats::~debug_stats()
{
}

void debug_stats::init(font_overlay * overlay)
{
	// Setup Overlay
	debug_stats::font_overlay_ptr = overlay;

	// Setup text
	font_overlay_ptr->add_font("FPS:");
	font_overlay_ptr->add_font("CPS:");
	font_overlay_ptr->add_font("LAG:");
}

void debug_stats::update_FPS()
{
	fps_counter++;
	sf::Time elapsed = fps_clock.getElapsedTime();
	if (elapsed.asSeconds() > 1.0f)
	{
		font_overlay_ptr->set_text(0, "FPS: " + std::to_string(fps_counter));
		fps_clock.restart();
		fps_counter = 0;
	}
}

void debug_stats::update_CPS()
{
	sf::Time elapsed = cps_clock.getElapsedTime();
	if (elapsed.asSeconds() > 1.0f)
	{
		font_overlay_ptr->set_text(1, "CPS: " + std::to_string(cps_counter));
		cps_clock.restart();
		cps_counter = 0;
	}
	cps_counter++;
}

void debug_stats::update_LAG()
{
	sf::Time elapsed = lag_clock.getElapsedTime();
	if (elapsed.asSeconds() > 1.0f)
	{
		font_overlay_ptr->set_text(2, "LAG: " + std::to_string(lag_counter));
		lag_clock.restart();
		lag_counter = 0;
	}
	lag_counter++;
}