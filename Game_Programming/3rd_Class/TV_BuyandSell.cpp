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
			cout << "������ �����ϴ�." << endl;
			return false;
		}
		else return true;
	}
public:
	TV(string name = "NONAMED")
		: power(false), channel(0), max_channel(100), volume(0), max_volume(100), model_name(name)
	{
		cout << "[TV��ü ����]" << endl;
		cout << "�𵨸�: " << name << endl;
	}
	void turnOn() { power = true; }
	void turnOff() { power = false; }
	void SetChannel(int channel_number = 0)
	{
		if (!IsPower(power)) return;
		if (channel_number > max_channel || channel_number < 0)
		{
			cout << "ä�� ���� ���Դϴ�." << endl;
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
		if (volume < 0) volume = 0; //�����÷ο�?
		cout << "Volume = " << volume << endl;
	}
	void Display()
	{
		cout << "[" << model_name << "]" << endl; //����. ����� ����� �ȵ�..
		cout << "Channel = " << channel << endl;
		cout << "Volume = " << volume << endl;
	}
	~TV()
	{
		cout << "[TV��ü�Ҹ�]" << endl;
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
	void TV_registration(string name = "NONAMED") //�Ǹ��� TV���
	{
		TV* TVforSell = new TV(name);
	}
	TV* Sell(int sale_price)
	{
		TV* sell = TVforSell;
		TVforSell = NULL; //�Ǹ������� �������� ����
		money += sale_price;
		return sell; //�Ǹ�TV�� ������ ��ȯ
	}
	TV* GetTV()
	{
		return TVforSell;
	}
	void SellerInfo()
	{
		cout << "������ �ݾ�: " << money << endl;
		cout << "������ TV: " << endl;
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
	TV* myTV; //�ִ� 1���� ������ ������ ����.
public:
	TVBuyer(int _money = 1000) : money(_money), myTV(NULL)
	{
	}
	void Buy(TVSeller& seller, int Purchase) //������ �߽ɼ���
	{
		cout << "[������ TVȮ��]" << endl;
		if (seller.GetTV() == NULL)
		{
			cout << "�Ǹ��ϴ� TV�� �����ϴ�." << endl;
			return;
		}
		else seller.GetTV()->Display();
		myTV = seller.Sell(Purchase); //���űݾ� ����
		money -= Purchase;
	}
	TV* GetTV()
	{
		return myTV;
	}
	void BuyerInfo()
	{
		cout << "������ �ݾ�: " << money << endl;
		cout << "������ TV: " << endl;
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
	buyer.Buy(seller, 1500); //1500�� �ְ� TV����
	buyer.BuyerInfo();
	return 0;
}