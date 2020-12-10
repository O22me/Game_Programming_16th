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
		cout << "bicycle.Constructor : \t\t" << this << endl;
	}
	void Accel() { speed++; }
	void Break() { speed--; }
	void SetGear(int gear)
	{
		this->gear = gear;
	}
	~bicycle()
	{
		cout << "~bicycle.Destructor : \t\t" << this << endl;
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
		cout << "Motorcycle.Constructor : \t" << this << endl;
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
		cout << "~Motorcycle.Destructor : \t" << this << endl;
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
		cout << "Truck.Constructor : \t\t" << this << endl;
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
		cout << "~Truck.Destructor : \t\t" << this << endl;
	}
};

int main(void)
{
	bicycle bike(1);
	Motorcycle motor(2, "Bull");
	Truck Cybertruck(4, "Perfect", 1000);
	return 0;
}