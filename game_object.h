#pragma once

class game_object
{
public:
	//virtual void draw() = 0;
	virtual void compute(float delta) = 0;
};