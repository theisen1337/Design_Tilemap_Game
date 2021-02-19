#pragma once

class GameState
{
public:
	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	//virtual void control_handler() = 0;
	//virtual void control_handler_delta(const float dt) = 0;
};

