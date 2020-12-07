#include <iostream>

using namespace std;

class Parent
{
public:
	virtual void Display()
	{
		cout << "Parent" << endl;
	}
};

class ChildA : public Parent
{
public:
	void Display() override
	{
		cout << "ChildA" << endl;
	}
};

class ChildB : public Parent
{
public:
	void Display() override
	{
		cout << "ChildB" << endl;
	}
};

void PolymorphismExceptionMain()
{

}