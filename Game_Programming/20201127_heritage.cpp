#include <iostream>

using namespace std;

class Vehicle
{
protected:
	int m_gear;
	int m_speed;
	int m_seater;
public:
	Vehicle(int gear = 0, int speed = 0, int seater = 1) //기본생성자
	{
		m_gear = gear;
		m_speed = speed;
		m_seater = seater;
		cout << "Vehicle(생성) : [" << this << "]" << endl;
	}
	void Accelarator() //가속
	{
		m_speed++;
	}
	void Break() //감속
	{
		m_speed--;
	}
	void SetGear(int input_gear) //기어변경
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
		cout << "Vehicle(소멸) : [" << this << "]" << endl;
	}
};
class Engine : public Vehicle
{
protected:
	string m_nEngine;
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
	
};
class bus : public Engine
{

};
class truck : public Engine
{
	int carry_capacity;
	truck(string engine_name = "truck_engine", int capacity = 0)
	{
		m_nEngine = engine_name;
		carry_capacity = capacity;
	}
};
int main()
{
	bicycle bike(10, 10, 2);
	bike.Display();

	truck cyber;
	cyber.SetGear(2);
	cyber.Accelarator();
	cyber.Display();
	return 0;
}