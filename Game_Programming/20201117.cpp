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
	/*CCar()
	{
		m_nSpeed = 0;
		m_nGear = 0;
		m_strColor = "gray";
	}*/
	//private: //�����ڰ� ������ �ȵǸ� �޸𸮸� �ܺο��� �Ҵ��Ҽ�����.
public://�ʱ�ȭ ���: ��������� �ʱⰪ�� ������.
	CCar(string color = "gray") :MaxSpeed(100) //�Լ��� �����ε�
	{
		m_nSpeed = 0;
		m_nGear = 0;
		m_strColor = color;
		cout << "CCar[" << this << "]:" << m_strColor << endl;
	}
	CCar(const CCar& car) :MaxSpeed(100)
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
};

//�ڵ������� -> ��༭�ۼ�(�ɼ�) -> ���� -> ���
void CarMain()
{

	cout << "CarMain Start" << endl;
	//�ֹ��ڰ� �������� ������ �����Ҽ��ִ�.
	CCar cCar("red"); //��ü����(�����Ҵ�) //�����ڳ� �Ҹ��ڰ� �ܺο��� ���ٺҰ��� �����Ұ�.
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
	//cCar.m_strColor = "red"; //�������� ������ ���� �ٲܼ��ִ�.(�̷��� ������ ���� ���˵ȴ�)
	cCar.SetColor("red"); //���ο��� ����޾Ƽ� ������ �����Ѵ�.
	cCar.Accelerator();
	cCar.Display();
	cCar.Break();
	cCar.Display();
	delete pCar; //�Ҹ��ڰ� �ܺο������ٺҰ����ϸ� ���������.
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
	ClassTestMain();
	cout << "Main End" << endl;
}