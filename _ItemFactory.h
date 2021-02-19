#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <functional>
#include <map>

#include "game_object.h"

#include "track_object.h"
#include "player_object.h"

using namespace std;

class _ItemFactory {
public:
	static _ItemFactory* _ItemFactory::Instance() {
		static _ItemFactory factory;
		return &factory;
	}

	shared_ptr<game_object> _ItemFactory::Create(string name) {
		game_object* instance = nullptr;

		// find name in the registry and call factory method.
		auto it = factoryFunctionRegistry.find(name);
		if (it != factoryFunctionRegistry.end())
		{
			instance = it->second();
		}

		// wrap instance in a shared ptr and return
		if (instance != nullptr)
		{
			return std::shared_ptr<game_object>(instance);
		}
		else
		{
			return nullptr;
		}
	}
	void _ItemFactory::RegisterFactoryFunction(string name,
		std::function<game_object* (void)> classFactoryFunction) {
		// register the class factory function
		factoryFunctionRegistry[name] = classFactoryFunction;
	}
	map<string, function<game_object* (void)>> factoryFunctionRegistry;
};


template<class T>
class ItemRegistrar 
{
public:
	ItemRegistrar(string className)
	{
		// register the class factory function 
		_ItemFactory::Instance()->RegisterFactoryFunction(name,
			[](void) -> game_object * { return new T(); });
	}
};

static ItemRegistrar<track_object> registrar1("one");
static ItemRegistrar<player_object> registrar2("two");