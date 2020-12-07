#include <iostream>
#include <cstring>

using namespace std;

//�ڵ��� - �߻�ȭ
//�Ӽ�-�ʵ�(����:������): �ӵ�,���,����
//����-�޼���(�Լ�:�˰���): �����ϱ�(�����д�),�����ϱ�(�극��ũ),����,
//�ػ����� ���� �ֹ��Ҷ� ���Ҽ��ִ�.

//Ŭ����: �߻�ȭ�� ��ü�� Ŭ������ ���赵�� ������ִ�.
//�⺻���(�ڵ�): ����ü�� public, Ŭ������ private
class Car
{
	//����������: Ŭ�������� ����� �Ӽ��� �����Ѵ�.(���� ��� ���� ������� ������ �޶������ִ�)
	//���������ڷ� private, protected, public�� �ִ�.
private:
	int m_nSpeed = 0;
	int m_nGear = 0;
	string m_strColor;
	const int MaxSpeed;
	static int m_nCount; //��������Լ��� ����, ��� Ŭ������ ��ü�� �����ȴ�.
public:
	Car(string color = "gray", int speed = 0, int gear = 0)
		: m_strColor(color), m_nSpeed(speed), m_nGear(gear), MaxSpeed(100) //�̴ϼȶ������� �̿��� const ���� �ʱ�ȭ(�ʼ�)
	{
		cout << "Car[" << m_nCount << "]" << this << endl;
		m_nCount++;
		cout << "m_nCount : " << m_nCount << endl;
	}
	//���������
	Car(const Car& car) :MaxSpeed(100)
	{
		//memcpy(this, &car, sizeof(CCar)); //���ڿ���ü�� �޸𸮺��簡 �Ұ����ϴ�.
		this->m_nSpeed = car.m_nSpeed;
		this->m_nGear = car.m_nGear;
		this->m_strColor = car.m_strColor;
		cout << "CCar Copy[" << this << "]:" << m_strColor << endl;
	}
	//���Կ�����
	void operator = (const Car& car)
	{
		*this = car;
		cout << "Car" << this << "=" << &car << endl;
	}
	//private : //�����Ҵ�(��ü�����Ұ�, �����Ҵ��� ���� �׷��� ��ü�����Ұ�(�޸𸮴���..)
	~Car()
	{
		m_nGear = 0;
		cout << "~CCar[" << this << "]:" << m_strColor << endl;
		m_nCount--; //��������Լ�
		cout << "m_nCount : " << m_nCount << endl;
	}
	void Accelerator()
	{
		m_nSpeed++;
	}
	void Break()
	{
		m_nSpeed--;
	}
	void SetGear(int nGear) //setter(������)
	{
		m_nGear = nGear;
	}
	int GetGear() //getter(������)
	{
		return m_nGear;
	}
	void SetColor(string color)
	{
		m_strColor = color;
	}
	void Display()
	{
		cout << "Color:" << m_strColor << endl;
		cout << "Speed:" << m_nSpeed << endl;
		cout << "Gear:" << m_nGear << endl;
	}
public:
	static int GetCount() //�����������
	{
		//m_nCount = 0; //��ü�� �������̹Ƿ� �Ϲ� ����� �̿��� �� ����.
		return m_nCount;
	}
	enum EGEAR { P, R, N, D }; //��
};
//������������� ��� ��ü�� �����Ǿ��ϰ� ��ü ���������� ������ �����ؾ��ϹǷ�, 
//���������� ��Ÿ�� ���� ����. �׷��Ƿ�, ��������ó�� ���� ����ؾ��Ѵ�.
int Car::m_nCount = 0; //��������Լ��� ����

void SwapCarVal(Car a, Car b)
{
	Car temp = a;
	a = b;
	b = temp;
}
void SwapCarPtr(Car* pA, Car* pB)
{
	Car temp = *pA;
	*pA = *pB;
	*pB = temp;
}
void SwapCarRef(Car& a, Car& b)
{
	Car temp = a;
	a = b;
	b = temp;
}
void SwapCarMain()
{
	Car cCarRed("red");
	Car cCarBlue("blue");
	cout << "##### Origin #####" << endl;
	cCarRed.Display();
	cCarBlue.Display();
	SwapCarVal(cCarRed, cCarBlue);
	cout << "##### Value #####" << endl;
	cCarRed.Display();
	cCarBlue.Display();
	SwapCarPtr(&cCarRed, &cCarBlue);
	cout << "##### Pointer #####" << endl;
	cCarRed.Display();
	cCarBlue.Display();
	SwapCarRef(cCarRed, cCarBlue);
	cout << "##### Reference #####" << endl;
	cCarRed.Display();
	cCarBlue.Display();
}

//TV Ŭ������ �ۼ��ϰ� TV�� �����ϵ� Ŭ������ Ȱ���ϱ�
//TV ���� : ����, �Է¹��, ä�μ���, ��������
class TV //TV�� ��ü
{
	//��� ����
private:
	bool m_onoff;
	int m_channel = 0;
	int m_volume = 0;
	string m_input_port;
	string m_model_name;
	const int max_channel; //�ִ� ä�μ� ����
public:
	//������ //const ������ �ݵ�� �̴ϼȶ������� �ʱ�ȭ�ؾ���.
	TV(bool onoff = false, int channel = 0, int volume = 0, string input_port = "NONE")
		: m_onoff(onoff), m_channel(channel), m_volume(volume), m_input_port(input_port), max_channel(100)
	{
	}
	TV(string name = "NONE") : m_model_name(name), max_channel(100) 
	{
	}
	//�̸� ���� �Լ�
	void SetName(string name)
	{
		m_model_name = name;
	}
	//�������� �Լ�
	void SwitchPower()
	{
		m_onoff = !m_onoff;
	}
	//Channel ���� ȣ���Լ�
	void SetChannel(int channel)
	{
		m_channel = channel;
	}
	void ChannelUp()
	{
		m_channel++;
	}
	void ChannelDown()
	{
		m_channel--;
	}
	int GetChannel() //ä�ι�ȣ ��ȯ
	{
		return m_channel;
	}
	//Volume ���� ȣ���Լ�
	void VolumeUp()
	{
		m_volume++;
	}
	void VolumeDown()
	{
		m_volume--;
	}
	//InputPort ���� �Լ�
	void SetInputPort(string input_port)
	{
		m_input_port = input_port;
	}
	string GetInputPort()
	{
		return m_input_port;
	}
	//�� ���� ���
	void Display()
	{
		cout << "[�𵨸�: " << m_model_name << "]" << endl;
		cout << "Channel : " << m_channel << endl;
		cout << "Volume : " << m_volume << endl;
		cout << "Input Port : " << m_input_port << endl;
	}
	~TV() //�Ҹ���
	{
		m_onoff = false;
		Display();
		cout << endl;
		cout << "Power : " << m_onoff << endl;
	}
};
void TVInterface()
{
	string input_port;
	cout << "�ܺ��Է���Ʈ : ";
	cin >> input_port;
	TV tv(input_port);
	cout << "##### TV control start #####" << endl;
	while (input_port != "turnoff") {
		cout << "You can choose ChannelUp/Down/Set VolumeUp/Down Inputport, Display and turnoff" << endl;
		cin >> input_port;
		if (input_port == "ChannelUp") {
			tv.ChannelUp();
		}
		else if (input_port == "ChannelDown") {
			tv.ChannelDown();
		}
		else if (input_port == "ChannelSet") {
			int channel;
			cout << "Input Channel";
			cin >> channel;
			tv.SetChannel(channel);
		}
		else if (input_port == "VolumeUp") {
			tv.VolumeUp();
		}
		else if (input_port == "VolumeDown") {
			tv.VolumeDown();
		}
		else if (input_port == "Inputport") {
			string input;
			cout << "Port : ";
			cin >> input;
			tv.SetInputPort(input);
		}
		else if (input_port == "Display") {
			tv.Display();
		}
		else cout << "Wrong input!" << endl;
	}
	cout << "##### TV control end #####" << endl;
}
//TV���� : �ǸŵǴ� TV���, TV����, �Ǹŵ� TV����
void PrintMenu()
{
	cout << "1. TV ���" << endl;
	cout << "2. TV ����" << endl;
	cout << "3. TV ��ϻ���" << endl;
	cout << "4. EXIT" << endl;
}
void TVselling()
{
	cout << "##### TV Selling start #####" << endl;

	bool exit = false;
	int input_number = 0;
	while (!exit)
	{
		PrintMenu();
		cin >> input_number;
		switch (input_number)
		{
		case 1: 
		}
	}

	cout << "##### TV Selling end #####" << endl;
}
//�ڵ������� -> ��༭�ۼ�(�ɼ�) -> ���� -> ���
void CarMain()
{
	Car* pCarA;
	cout << pCarA->GetCount() << endl; //��ü�� ������ static����� ��ü���������� ������ ������.
	cout << Car::GetCount() << endl; //��.��.��.��...

	cout << "CarMain Start" << endl;
	cout << Car::GetCount() << endl;
	// �ڵ��� ����(����, ����, ����) ����.
	// �ɼ�(�ֹ��ڿ�û) : ���󺯰�, ũ�⺯��	, ���ݰ���			<-�⺻���� ������ �������� ����?
	// ���� : ����, ũ��(����, ����, ������ �ִٰ� ġ��)
	// ��� : ����� �������Է�
	cout << "Set Color : ";
	string color;
	cin >> color;
	Car cCar(color); //��ü����(�����Ҵ�) //�����ڳ� �Ҹ��ڰ� �ܺο��� ���ٺҰ��� �����Ұ�.
	Car cCarA("blue");
	Car arrCar[3];
	//C++�� ���: ��ü == �������̽�(�����Ҵ��̵� �����Ҵ��̵� �޸𸮰� �Ҵ�Ǹ� ��ü�̸� �ν��Ͻ���)
	//Java/C#�� ���
	//��ü: ����� �����ϴ� ��.
	//�ν��Ͻ�: ������ ���. 
	//��ü = �ν��Ͻ�
	Car* pCar = new Car("green");//��ü: �����ڰ� �ܺο��� ���ٺҰ����ϸ� �����Ұ�.
	Car& refCar = cCar;
	cout << "[pCar Display]" << endl;
	pCar->Display();
	//cCar.m_strColor = "red"; //�������� ������ ���� �ٲܼ��ִ�. (�̷��� ������ ���� ���˵ȴ�)
	cCar.SetColor("red"); //���ο��� ����޾Ƽ� ������ �����Ѵ�.
	cCar.Accelerator();
	cout << "[cCar Display]" << endl;
	cCar.Display();
	cCar.Break();
	cout << "[cCar Display]" << endl;
	cCar.Display();
	delete pCar; //�Ҹ��ڰ� �ܺο��� ���ٺҰ����ϸ� ���������. <-????
	cout << Car::GetCount() << endl;
	cout << "CarMain End" << endl;
}

void ClassTestMain()
{
	Car cCarA;
	Car cCarB();//�Լ��� �������� ���
	Car cCarC("blue");
	Car cCarD = Car("red"); //�ӽð�ü�� �����Ǿ� �����.
	Car cCarE = cCarA;
	cCarA.Display();
	//cCarB.Display(); //��ü�� ����.
	cCarC.Display();
	cCarD.Display();
}

void CarInterfaceMain()//�ڵ����� �����ϴ� ����� �������̽�(UI) �����ϱ�: �ܼ־�
{
	string strInput;
	cout << "InputCarColor:" << strInput;
	cin >> strInput;
	Car cCar(strInput);
	cout << "#### Drive Start ####" << endl;
	while (strInput != "exit")
	{
		cout << "Select Car Interface(accel,break,gear(P,R,N,D),exit)";
		cin >> strInput;
		if (strInput == "accel")
			cCar.Accelerator();
		else if (strInput == "break")
			cCar.Break();
		else if (strInput == "P")
			cCar.SetGear(Car::EGEAR::P);
		else if (strInput == "R")
			cCar.SetGear(Car::EGEAR::R);
		else if (strInput == "N")
			cCar.SetGear(Car::EGEAR::N);
		else if (strInput == "D")
			cCar.SetGear(Car::EGEAR::D);
		cCar.Display();
	}
	cout << "#### Driving End ####" << endl;
}

int g_nData;

void main()
{
	cout << "Main Start" << endl;
	//g_nData++;
	//CarMain();
	//SwapCarMain();
	//ClassTestMain();
	//CarInterfaceMain();
	TVInterface();
	cout << "Main End" << endl;
}