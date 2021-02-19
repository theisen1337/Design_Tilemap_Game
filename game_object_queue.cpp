#include "game_object_queue.h"



game_object_queue::game_object_queue()
{

}


game_object_queue::~game_object_queue()
{

}

void game_object_queue::init(master_objects& m_obj)
{
	m_obj = m_obj;
}

void game_object_queue::draw()
{

}

void game_object_queue::compute(float delta)
{

}

void game_object_queue::add(game_object &object)
{
	game_queue.push_back(object);
}

void game_object_queue::add_name(std::string item)
{
	auto instanceTwo = _ItemFactory::Instance()->Create("two");
}
