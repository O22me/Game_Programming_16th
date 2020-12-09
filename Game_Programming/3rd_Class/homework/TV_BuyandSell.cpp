#include <iostream>
#include <cstring>
#include <list>
#define MAXIMUM_SALES 5
using namespace std;

class TV
{
private:
	bool power;
	unsigned int channel;
	const int max_channel; //100
	unsigned int volume;
	const int max_volume; //100
	string model_name;
	bool IsPower(bool power)
	{
		if (!power)
		{
			cout << "전원이 없습니다." << endl;
			return false;
		}
		else return true;
	}
public:
	TV(string name = "NONAMED")
		: power(false), channel(0), max_channel(100), volume(0), max_volume(100), model_name(name)
	{
		cout << "[TV객체 생성]" << endl;
		cout << "모델명: " << name << endl;
	}
	void turnOn() { power = true; }
	void turnOff() { power = false; }
	void SetChannel(int channel_number = 0)
	{
		if (!IsPower(power)) return;
		if (channel_number > max_channel || channel_number < 0)
		{
			cout << "채널 범위 밖입니다." << endl;
			return;
		}
		else channel = channel_number;
	}
	void ChannelUp()
	{
		if (!IsPower(power)) return;
		channel = (channel++) % max_channel;
	}
	void ChannelDown()
	{
		if (!IsPower(power)) return;
		channel = (channel--) % max_channel;
	}
	void VolumeUp()
	{
		if (!IsPower(power)) return;
		volume++;
		if (volume > max_volume) volume = max_volume;
		cout << "Volume = " << volume << endl;
	}
	void VolumeDown()
	{
		if (!IsPower(power)) return;
		volume--;
		if (volume < 0) volume = 0; //오버플로우?
		cout << "Volume = " << volume << endl;
	}
	void Display()
	{
		cout << "[" << model_name << "]" << endl; //오류. 멤버가 출력이 안됨..
		cout << "Channel = " << channel << endl;
		cout << "Volume = " << volume << endl;
	}
	~TV()
	{
		cout << "[TV객체소멸]" << endl;
	}
};

class TVSeller
{
private:
	int money;
	TV* TVforSell;
public:
	TVSeller(int _money = 1000) : money(_money), TVforSell(NULL)
	{
	}
	void TV_registration(string name = "NONAMED") //판매할 TV등록
	{
		TV* TVforSell = new TV(name);
	}
	TV* Sell(int sale_price)
	{
		TV* sell = TVforSell;
		TVforSell = NULL; //판매했으니 보유하지 않음
		money += sale_price;
		return sell; //판매TV의 포인터 반환
	}
	TV* GetTV()
	{
		return TVforSell;
	}
	void SellerInfo()
	{
		cout << "보유한 금액: " << money << endl;
		cout << "보유한 TV: " << endl;
		GetTV()->Display();
	}
	~TVSeller()
	{
		delete TVforSell;
	}
};

class TVBuyer
{
private:
	int money;
	TV* myTV; //최대 1개만 가지는 것으로 가정.
public:
	TVBuyer(int _money = 1000) : money(_money), myTV(NULL)
	{
	}
	void Buy(TVSeller& seller, int Purchase) //구매자 중심설계
	{
		cout << "[구매할 TV확인]" << endl;
		if (seller.GetTV() == NULL)
		{
			cout << "판매하는 TV가 없습니다." << endl;
			return;
		}
		else seller.GetTV()->Display();
		myTV = seller.Sell(Purchase); //구매금액 전달
		money -= Purchase;
	}
	TV* GetTV()
	{
		return myTV;
	}
	void BuyerInfo()
	{
		cout << "보유한 금액: " << money << endl;
		cout << "보유한 TV: " << endl;
		GetTV()->Display();
	}
	~TVBuyer()
	{
		delete myTV;
	}
};

int main(void)
{
	TVSeller seller(10000);
	TVBuyer buyer(10000);
	seller.TV_registration("SAMSUNG QLED TV");
	seller.SellerInfo();
	buyer.Buy(seller, 1500); //1500을 주고 TV구매
	buyer.BuyerInfo();
	return 0;
}