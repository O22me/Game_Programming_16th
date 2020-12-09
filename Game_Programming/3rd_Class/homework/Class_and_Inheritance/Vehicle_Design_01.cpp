#include <iostream>
#include <cstring>

using namespace std;

class bicycle
{
private:
	int gear;
	int speed;
	int seat;
public:
	bicycle(int _seat) : gear(0), speed(0), seat(_seat)
	{
		cout << "bicycle(int _seat = 0) = Constructor : " << this << endl;
	}
	void Accel() { speed++; }
	void Break() { speed--; }
	void SetGear(int gear)
	{
		this->gear = gear;
	}
};

class Motorcycle
{
private:
	int gear;
	int speed;
	int seat;
	char* engine;
public:
	Motorcycle(int _seat, const char* name)
		: gear(0), speed(0), seat(_seat)
	{
		engine = new char[strlen(name) + 1];
		strcpy_s(engine, strlen(name) + 1, name);
	}
	void Accel() { speed++; }
	void Break() { speed--; }
	void SetGear(int gear)
	{
		this->gear = gear;
	}
	~Motorcycle()
	{
		delete[] engine;
	}
};
// class Bus class Motorcycle이랑 동일하므로 생략

class Truck
{
private:
	int gear;
	int speed;
	int seat;
	char* engine;
	int max_capacity_kg;
public:
	Truck(int _seat, const char* engine_name, int capacity)
		: gear(0), speed(0), seat(_seat), max_capacity_kg(capacity)
	{
		engine = new char[strlen(engine_name) + 1];
		strcpy_s(engine, strlen(engine_name) + 1, engine_name);
	}
	void Accel() { speed++; }
	void Break() { speed--; }
	void SetGear(int gear)
	{
		this->gear = gear;
	}
	~Truck()
	{
		delete[] engine;
	}
};