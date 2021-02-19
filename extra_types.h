#pragma once
enum game_state { loading, main_menu, main_game, exit_app };


#include "font_overlay.h"
#include "debug_stats.h"

struct master_objects {
	// TODO Move to data_types.h make a global object?
	// Maybe don't move.

	/* Font overlay, for text that runs over the screen. */
	font_overlay font_layer;

	/* debug stats */
	debug_stats debug;
};