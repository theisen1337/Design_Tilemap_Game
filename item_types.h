#pragma once
#include "game_object.h"


#include "track_object.h"
#include "player_object.h"


namespace item
{
	game_object t;
}



template<class T>
class Object_Registrar {
public:
	Registrar(std::string ItemName)
	{
		ItemFactory::Instance()->Regi
	}
};