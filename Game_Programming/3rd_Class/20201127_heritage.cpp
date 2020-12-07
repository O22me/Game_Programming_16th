#include <iostream>

using namespace std;

class Vehicle
{
protected:
	int m_gear;
	int m_speed;
	int m_seater;
public:
	Vehicle(int gear = 0, int speed = 0, int seater = 1)
		: m_gear(gear), m_speed(speed), m_seater(seater)
	{
		cout << "Vehicle(����) : [" << this << "]" << endl;
	}
	void Accelarator() //����
	{
		m_speed++;
	}
	void Break() //����
	{
		m_speed--;
	}
	void SetGear(int input_gear) //����
	{
		m_gear = input_gear;
	}
	void Display()
	{
		cout << "Gear :  \t" << m_gear << endl;
		cout << "Speed : \t" << m_speed << endl;
		cout << "Seat :  \t" << m_seater << endl;
	}
	~Vehicle()
	{
		cout << "Vehicle(�Ҹ�) : [" << this << "]" << endl;
	}
};
class Engine : public Vehicle
{
protected:
	int m_nEngine;
public:
	Engine() : m_nEngine(0)
	{
	}
};
class bicycle : public Vehicle
{
public:
	bicycle(int gear = 0, int speed = 0, int seater = 1)
	{
		m_gear = gear;
		m_speed = speed;
		m_seater = seater;
	}
};
class motorcycle : public Vehicle
{
public:
	motorcycle(int gear = 0, int speed = 0, int seater = 1)
	{
		m_gear = gear;
		m_speed = speed;
		m_seater = seater;
	}
};
class bus : public Engine
{
public:
	bus(int engine, int gear = 0, int speed = 0, int seater = 15)
	{
		m_nEngine = engine;
		m_gear = gear;
		m_speed = speed;
		m_seater = seater;
		cout << "Bus(����) : [" << this << "]" << endl;
	}
	~bus()
	{
		cout << "Bus(�Ҹ�) : [" << this << "]" << endl;
	}
};
class truck : public Engine
{
protected:
	int carry_capacity;
public:
	truck(int engine = 0, int capacity = 1000)
	{
		m_nEngine = engine;
		carry_capacity = capacity;
		cout << "Truck(����) : [" << this << "]" << endl;
	}
	~truck()
	{
		cout << "Truck(�Ҹ�) : [" << this << "]" << endl;
	}
};
int main()
{
	bicycle bike(10, 10, 2);
	bike.Display();
	bike.Accelarator();
	return 0;
}