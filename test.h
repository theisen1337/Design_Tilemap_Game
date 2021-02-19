


#include <functional>
#include <map>
#include <memory>
#include <string>

#include <iostream>
using namespace std;

class MyBaseClass
{
public:
	virtual void doSomething() = 0;
};

class DerivedClassOne : public MyBaseClass
{
public:
	DerivedClassOne() {};
	virtual ~DerivedClassOne() {};

	virtual void doSomething() { cout << "I am class one" << endl; }
};

class DerivedClassTwo : public MyBaseClass
{
public:
	DerivedClassTwo() {};
	virtual ~DerivedClassTwo() {};

	virtual void doSomething() { cout << "I am class two" << endl; }
};


class MyFactory
{
public:

	MyFactory* Instance();

	static shared_ptr<MyBaseClass> Create(string name);

	map<string, function<MyBaseClass* (void)>> factoryFunctionRegistry;
	
};


MyFactory::Instance()->RegisterFactoryFunction(name, classFactoryFunction);


class Registrar {
public:
	Registrar(string className, function<MyBaseClass* (void)> classFactoryFunction);
};

Registrar::Registrar(string name, function<MyBaseClass* (void)> classFactoryFunction)
{
	// register the class factory function 
	MyFactory::Instance()->RegisterFactoryFunction(name, classFactoryFunction);
}
























