#include <iostream>
#include <string>

using namespace std;

//자동차 - 추상화
//속성-필드(변수:데이터): 속도,기어,색상
//동작-메서드(함수:알고리즘): 가속하기(가속패달),감속하기(브레이크),기어설정,
//※색상은 차를 주문할때 정할수있다.

//클래스: 추상화된 객체를 클래스로 설계도를 만들수있다.
//구조체 <-> 클래스 : 기본멤버 public / private
class Car
{
	//접근제어자: 클래스에서 변경될 속성을 제한한다.(만들 대상에 따라 멤버에서 설정은 달라질수있다)
//private: //클래스외부에 접근을 막는다.
	//멤버변수
	int m_nSpeed = 0;
	int m_nGear = 0;
	string m_strColor;
	const int MaxSpeed;
	static int m_nCount; //정적멤버함수의 선언, 모든 클래스의 객체가 공유된다.

	//멤버함수
public: //클래스외부에서 접근을 가능하게 만든다.
	//생성자: 객체가 생성될때 호출되는 함수.
	//리턴값없음. 매개변수있음. 디폴트매개변수가능. 오버로딩가능.
	/*
	CCar() :MaxSpeed(100) //<-기본생성자
	{
		m_nSpeed = 0;
		m_nGear = 0;
	}
	*/
	//private: //생성자가 접근이 안되면 메모리를 외부에서 할당할수없다.
public://초기화 목록: 멤버변수에 초기값을 설정함.
	//this는 객체의 주소값.
	Car(string color = "gray", int speed = 0, int gear = 0) :MaxSpeed(100) //함수의 오버로딩<-기본생성자(괄호 내 string 이 정해져있음)
	{
		cout << "Car[" << m_nCount << "]" << this << endl;
		m_strColor = color;
		m_nSpeed = speed;
		m_nGear = gear;
		m_nCount++;
		cout << "m_nCount : " << m_nCount << endl;
	}
	Car(const Car& car) :MaxSpeed(100) //복사생성자
	{
		//*this = car;
		//memcpy(this, &car, sizeof(CCar)); //문자열객체는 메모리복사가 불가능하다.
		this->m_nSpeed = car.m_nSpeed;
		this->m_nGear = car.m_nGear;
		this->m_strColor = car.m_strColor;
		cout << "CCar Copy[" << this << "]:" << m_strColor << endl;
	}
	//대입연산자
	void operator = (const Car& car)
	{
		*this = car;
		cout << "Car" << this << "=" << &car << endl;
	}

	//private: //객체가 소멸자에서 
		//소멸자: 객체가 소멸할때 호출되는 함수.
		//리턴값없음. 매개변수X. 오버로딩X
	//private : //정적할당(객체생성불가, 동적할당은 가능 그러나 객체삭제불가(메모리누수..)
	~Car()
	{
		m_nGear = 0;
		cout << "~CCar[" << this << "]:" << m_strColor << endl;
		m_nCount--;
		cout << "m_nCount : " << m_nCount << endl;
	}

	//void SetSpeed(int speed) { m_nSpeed = speed; } //물리법칙상 변경이 불가능하다.
	void Accelerator()
	{
		m_nSpeed++;
	}
	void Break()
	{
		m_nSpeed--;
	}
	void SetGear(int nGear) //setter(설정자)
	{
		m_nGear = nGear;
	}
	int GetGear() //getter(접근자)
	{
		return m_nGear;
	}
	void SetColor(string color)
	{
		m_strColor = color;
	}
	void Display() //자동차 계기판
	{
		cout << "Color:" << m_strColor << endl;
		cout << "Speed:" << m_nSpeed << endl;
		cout << "Gear:" << m_nGear << endl;
	}
public:
	static int GetCount() //정적멤버변수
	{
		//m_nCount = 0; //객체가 생성전이므로 일반 멤버는 이용할 수 없다.
		return m_nCount;
	}
	enum EGEAR { P, R, N, D }; //기어값
};
//정적멤버변수는 모든 객체가 공유되야하고 객체 생성전에도 접든이 가능해야하므로, 
//지역변수는 나타낼 수가 없다. 그러므로, 전역변수처럼 만들어서 사용해야한다.
int Car::m_nCount = 0; //정적멤버함수의 정의

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


//TV 클래스를 작성하고 TV룰 조작하듯 클래스를 활용하기
//TV 조작 : 전원, 입력방식, 채널설정, 볼륨설정
class TV //TV그 자체
{
	//멤버 변수
	bool m_onoff;
	int m_channel = 0;
	int m_volume = 0;
	string m_input_port;
	string model_name;
	const int max_channel; //최대 채널수 제한
public:
	//기본생성자
	TV(bool onoff = false) : max_channel(100)
	{
		m_onoff = onoff;
		m_channel = 0;
		m_volume = 0;
		m_input_port = "HDMI";
	}
	//생성자
	TV(string input_port) : max_channel(100)
	{
		m_input_port = input_port;
	}
	//이름 설정 함수
	void SetName(string name)
	{
		model_name = name;
	}
	//전원관련 함수
	void SetPower()
	{
		m_onoff = !m_onoff;
	}
	//Channel 관련 호출함수
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
	//Volume 관련 호출함수
	void UpVolume()
	{
		m_volume++;
	}
	void DownVolume()
	{
		m_volume--;
	}
	//InputPort 관련 함수
	void SetInputPort(string input_port)
	{
		m_input_port = input_port;
	}
	string GetInputPort()
	{
		return m_input_port;
	}
	//현 상태 출력
	void Display() //현 상태 출력
	{
		cout << "Channel : " << m_channel << endl;
		cout << "Volume : " << m_volume << endl;
		cout << "Input Port : " << m_input_port << endl;
	}
	~TV() //소멸자
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
	cout << "외부입력포트 : ";
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
//TV구매 : 판매되는 TV등록, TV구매, 판매된 TV삭제
void PrintMenu()
{
	cout << "1. TV 등록" << endl;
	cout << "2. TV 구매" << endl;
	cout << "3. TV 등록삭제" << endl;
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
//자동차구매 -> 계약서작성(옵션) -> 생산 -> 배달
void CarMain()
{
	Car* pCarA;
	cout << pCarA->GetCount() << endl; //객체는 없으나 static멤버는 객체생성전에도 접근이 가능함.
	cout << Car::GetCount() << endl; //쓰.지.마.라...

	cout << "CarMain Start" << endl;
	cout << Car::GetCount() << endl;
	// 자동차 종류(소형, 중형, 대형) 선택.
	// 옵션(주문자요청) : 색상변경, 크기변경	, 가격공지			<-기본값을 변경할 것인지에 대한?
	// 생산 : 색상, 크기(소형, 중형, 대형만 있다고 치자)
	// 배달 : 출발지 도착지입력
	cout << "Set Color : ";
	string color;
	cin >> color;
	Car cCar(color); //객체생성(정적할당) //생성자나 소멸자가 외부에서 접근불가면 생성불가.
	Car cCarA("blue");
	Car arrCar[3];
	//C++의 경우: 객체 == 인터페이스(동적할당이든 정적할당이든 메모리가 할당되면 객체이며 인스턴스다)
	//Java/C#의 경우
	//객체: 대상을 참조하는 것.
	//인스턴스: 참조된 대상. 
	//객체 = 인스턴스
	Car* pCar = new Car("green");//객체: 생성자가 외부에서 접근불가능하면 생성불가.
	Car& refCar = cCar;
	cout << "[pCar Display]" << endl;
	pCar->Display();
	//cCar.m_strColor = "red"; //지나가던 행인이 색을 바꿀수있다. (이러한 행위는 법에 접촉된다)
	cCar.SetColor("red"); //주인에게 허락받아서 색상을 변경한다.
	cCar.Accelerator();
	cout << "[cCar Display]" << endl;
	cCar.Display();
	cCar.Break();
	cout << "[cCar Display]" << endl;
	cCar.Display();
	delete pCar; //소멸자가 외부에서 접근불가능하면 지울수없음. <-????
	cout << Car::GetCount() << endl;
	cout << "CarMain End" << endl;
}

void ClassTestMain()
{
	Car cCarA;
	Car cCarB();//함수의 선언으로 취급
	Car cCarC("blue");
	Car cCarD = Car("red"); //임시객체가 생성되어 복사됨.
	Car cCarE = cCarA;
	cCarA.Display();
	//cCarB.Display(); //객체가 없음.
	cCarC.Display();
	cCarD.Display();
}

void CarInterfaceMain()//자동차를 조작하는 사용자 인터페이스(UI) 구축하기: 콘솔앱
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