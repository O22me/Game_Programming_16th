#include <iostream>
#include <string>

using namespace std;

//�ڵ��� - �߻�ȭ
//�Ӽ�-�ʵ�(����:������): �ӵ�,���,����
//����-�޼���(�Լ�:�˰���): �����ϱ�(�����д�),�����ϱ�(�극��ũ),����,
//�ػ����� ���� �ֹ��Ҷ� ���Ҽ��ִ�.

//Ŭ����: �߻�ȭ�� ��ü�� Ŭ������ ���赵�� ������ִ�.
//����ü <-> Ŭ���� : �⺻��� public / private
class CCar
{
	//����������: Ŭ�������� ����� �Ӽ��� �����Ѵ�.(���� ��� ���� ������� ������ �޶������ִ�)
//private: //Ŭ�����ܺο� ������ ���´�.
	//�������
	int m_nSpeed = 0;
	int m_nGear = 0;
	string m_strColor;
	const int MaxSpeed;
	//����Լ�
public: //Ŭ�����ܺο��� ������ �����ϰ� �����.
	//������: ��ü�� �����ɶ� ȣ��Ǵ� �Լ�.
	//���ϰ�����. �Ű���������. ����Ʈ�Ű���������. �����ε�����.
	/*
	CCar() :MaxSpeed(100) //<-�⺻������
	{
		m_nSpeed = 0;
		m_nGear = 0;
	}
	*/
	//private: //�����ڰ� ������ �ȵǸ� �޸𸮸� �ܺο��� �Ҵ��Ҽ�����.
public://�ʱ�ȭ ���: ��������� �ʱⰪ�� ������.
	//this�� ��ü�� �ּҰ�.
	CCar(string color = "gray") :MaxSpeed(100) //�Լ��� �����ε�<-�⺻������(��ȣ �� string �� ����������)
	{
		m_nSpeed = 0;
		m_nGear = 0;
		m_strColor = color;
		cout << "CCar[" << this << "]:" << m_strColor << endl;
	}
	//????
	CCar(const CCar& car) :MaxSpeed(100) //���������
	{
		//*this = car;
		//memcpy(this, &car, sizeof(CCar)); //���ڿ���ü�� �޸𸮺��簡 �Ұ����ϴ�.
		this->m_nSpeed = car.m_nSpeed;
		this->m_nGear = car.m_nGear;
		this->m_strColor = car.m_strColor;
		cout << "CCar Copy[" << this << "]:" << m_strColor << endl;
	}
	

	//private: //��ü�� �Ҹ��ڿ��� 
		//�Ҹ���: ��ü�� �Ҹ��Ҷ� ȣ��Ǵ� �Լ�.
		//���ϰ�����. �Ű�����X. �����ε�X
	//private : //�����Ҵ�(��ü�����Ұ�, �����Ҵ��� ���� �׷��� ��ü�����Ұ�(�޸𸮴���..)
	~CCar()
	{
		m_nGear = 0;
		cout << "~CCar[" << this << "]:" << m_strColor << endl;
	}

	//void SetSpeed(int speed) { m_nSpeed = speed; } //������Ģ�� ������ �Ұ����ϴ�.
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
	void Display() //�ڵ��� �����
	{
		cout << "Color:" << m_strColor << endl;
		cout << "Speed:" << m_nSpeed << endl;
		cout << "Gear:" << m_nGear << endl;
	}
public:
	enum EGEAR { P, R, N, D }; //��
};
//TV Ŭ������ �ۼ��ϰ� TV�� �����ϵ� Ŭ������ Ȱ���ϱ�
//TV ���� : ����, �Է¹��, ä�μ���, ��������
class TV
{
	//��� ����
	bool m_onoff;
	int m_channel;
	int m_volume;
	string m_input_port;
	const int max_channel; //�ִ� ä�μ� ����
public:
	//�⺻������
	TV(bool onoff = false) : max_channel(100)
	{
		m_onoff = onoff;
		m_channel = 0;
		m_volume = 0;
		m_input_port = "HDMI";
	}
	//������
	TV(string input_port) : max_channel(100)
	{
		m_input_port = input_port;
	}
	//�������� �Լ�
	void SetPower()
	{
		m_onoff = !m_onoff;
	}
	//Channel ���� ȣ���Լ�
	void SetChannel(int channel)
	{
		m_channel = channel;
	}
	void UpChannel()
	{
		m_channel++;
	}
	void DownChannel()
	{
		m_channel--;
	}
	int GetChannel()
	{
		return m_channel;
	}
	//Volume ���� ȣ���Լ�
	void UpVolume()
	{
		m_volume++;
	}
	void DownVolume()
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
		cout << "Channel : " << m_channel << endl;
		cout << "Volume : " << m_volume << endl;
		cout << "Input Port : " << m_input_port << endl;
	}
	~TV()
	{
		Display();
		m_onoff = false;
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
			tv.UpChannel();
		}
		else if (input_port == "ChannelDown") {
			tv.DownChannel();
		}
		else if (input_port == "ChannelSet") {
			int channel;
			cout << "Input Channel";
			cin >> channel;
			tv.SetChannel(channel);
		}
		else if (input_port == "VolumeUp") {
			tv.UpVolume();
		}
		else if (input_port == "VolumeDown") {
			tv.DownVolume();
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
//�ڵ������� -> ��༭�ۼ�(�ɼ�) -> ���� -> ���
void CarMain()
{
	cout << "CarMain Start" << endl;
	// �ڵ��� ����(����, ����, ����) ����.
	// �ɼ�(�ֹ��ڿ�û) : ���󺯰�, ũ�⺯��	, ���ݰ���			<-�⺻���� ������ �������� ����?
	// ���� : ����, ũ��(����, ����, ������ �ִٰ� ġ��)
	// ��� : ����� �������Է�
	cout << "�ֹ� �� ������ �����ϼ��� : ";
	string color;
	cin >> color;
	CCar cCar(color); //��ü����(�����Ҵ�) //�����ڳ� �Ҹ��ڰ� �ܺο��� ���ٺҰ��� �����Ұ�.
	CCar cCarA("blue");
	CCar arrCar[3];
	//C++�� ���: ��ü == �������̽�(�����Ҵ��̵� �����Ҵ��̵� �޸𸮰� �Ҵ�Ǹ� ��ü�̸� �ν��Ͻ���)
	//Java/C#�� ���
	//��ü: ����� �����ϴ� ��.
	//�ν��Ͻ�: ������ ���. 
	//��ü = �ν��Ͻ�
	CCar* pCar = new CCar("green");//��ü: �����ڰ� �ܺο��� ���ٺҰ����ϸ� �����Ұ�.
	CCar& refCar = cCar;
	pCar->Display();
	//cCar.m_strColor = "red"; //�������� ������ ���� �ٲܼ��ִ�. (�̷��� ������ ���� ���˵ȴ�)
	cCar.SetColor("red"); //���ο��� ����޾Ƽ� ������ �����Ѵ�.
	cCar.Accelerator();
	cCar.Display();
	cCar.Break();
	cCar.Display();
	delete pCar; //�Ҹ��ڰ� �ܺο��� ���ٺҰ����ϸ� ���������. <-????
	cout << "CarMain End" << endl;
}

void ClassTestMain()
{
	CCar cCarA;
	CCar cCarB();//�Լ��� �������� ���
	CCar cCarC("blue");
	CCar cCarD = CCar("red"); //�ӽð�ü�� �����Ǿ� �����.
	CCar cCarE = cCarA;
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
	CCar cCar(strInput);
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
			cCar.SetGear(CCar::EGEAR::P);
		else if (strInput == "R")
			cCar.SetGear(CCar::EGEAR::R);
		else if (strInput == "N")
			cCar.SetGear(CCar::EGEAR::N);
		else if (strInput == "D")
			cCar.SetGear(CCar::EGEAR::D);
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
	//ClassTestMain();
	//CarInterfaceMain();
	TVInterface();
	cout << "Main End" << endl;
}