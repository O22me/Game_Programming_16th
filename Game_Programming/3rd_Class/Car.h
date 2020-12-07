#pragma once

#include <iostream>
using namespace std;

class Vehicle
{
protected: //�ڽ��� ���ٰ����ϰ� �ܺο��� ���ٺҰ�.
	int m_nGear = 0;
	int m_nSpeed = 0;
	int m_nSeats = 1;
public:
	Vehicle(int seat = 1) 
	{
		cout << "Vehicle["<<this<<"]" << endl;
		m_nSeats = seat;
	}
	~Vehicle() { cout << "~Vehicle[" << this << "]" << endl; }

	void Accel() { m_nSpeed++; }
	void Break() { m_nSpeed--; }
	void SetGear(int gear) { m_nGear = gear; }
	void SetSeats(int seat) { m_nSeats = seat; }
};

class Bike : public Vehicle
{
public:
	Bike() { cout << "Bike[" << this << "]" << endl;}
	~Bike() { cout << "~Bike[" << this << "]" << endl;}
};

class AutoBike : public Vehicle
{
	int m_nEngine;
public:
	AutoBike(int engine = 300) 
	{ 
		cout << "AutoBike[" << this << "]" << endl;
		m_nEngine = engine;
	}
	~AutoBike() { cout << "~AutoBike[" << this << "]" << endl; }
};

class Track : public Vehicle
{
	int m_nEngine;
	int m_nMaxWight;
public:
	Track(int engine = 3000, int wight = 1000) 
	{ 
		cout << "Track[" << this << "]" << endl;
		m_nEngine = engine; 
		m_nMaxWight = wight;
	}
	~Track() { cout << "~Track[" << this << "]" << endl; }
};

class Bus : public Vehicle
{
	int m_nEngine;
public:
	Bus(int engine = 7000, int seat = 30):Vehicle(seat)//�θ�������� ȣ��: �����ڸ� ���� ȣ���ϸ� �θ����� ���������ڿ� ������� ��밡��.
	{
		cout << "Bus[" << this << "]" << endl;
		m_nEngine = engine;
		///m_nSeats = seat; //�θ����� private�� �ƴϿ��� ���ٰ���.
	}
	~Bus() { cout << "~Bus[" << this << "]" << endl; }
};

void CarMain()
{
	Vehicle cVihvle;
	Bike cBike;
	AutoBike cAutoBike;
	Track cTrack;
	Bus cBus;
}