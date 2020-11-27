#include <iostream>

using namespace std;

class Vehicle
{
protected:
	int m_gear;
	int m_speed;
	int m_seater;
public:
	Vehicle()
	{
		m_gear = 0;
		m_speed = 0;
		m_seater = 1;
	}
	Vehicle(int seater, int gear, int speed) //기본생성자
	{
		m_gear = gear;
		m_speed = speed;
		m_seater = seater;
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
};
class bicycle : public Vehicle
{
	int m_engine = 0;
public:
	bicycle(int seats, int engine)
	{
		m_seater = seats;
		m_engine = engine;
	}
};
class motorcycle : public Vehicle
{
	string m_engine;
	motorcycle(string engine_name = NULL)
	{
		m_engine = engine_name;
	}
};
class bus : public Vehicle
{

};
class truck
{

};
void main()
{
	return;
}