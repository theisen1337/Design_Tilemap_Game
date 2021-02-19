#pragma once
#include "game_object.h"
#include <vector>
#include "extra_types.h"
#include "_ItemFactory.h"

class game_object_queue
{

public:
	game_object_queue();
	~game_object_queue();

	void init(master_objects &m_obj);
	void draw();
	void compute(float delta);
	void add(game_object &object);
	void add_name(std::string item);

private:

	//struct master_objects;
	std::vector<game_object> game_queue;
	master_objects m_obj;
};

