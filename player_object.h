#pragma once
#include "game_object.h"
#include "extra_types.h"


class player_object : game_object
{
public:
	player_object();
	~player_object();

	void init();
	void draw();
	void compute(float delta);
private:
};

