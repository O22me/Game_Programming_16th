#include <iostream>
#include <cstring>

using namespace std;

class Vehicle
{
private:
	int gear;
	int speed;
	int seat;
public:
	Vehicle(int _seat) : gear(0), speed(0), seat(_seat)
	{
		cout << "Vehicle.Constructor : \t" << this << endl;
	}
	void Accel() { speed++; }
	void Break() { speed--; }
	void SetGear(int gear)
	{
		this->gear = gear;
	}
};