#include <iostream>

using namespace std;

int main(void)
{
	int pizza_slices = 0;
	int person = -1;
	int slices_per_person = 0;

	cout << "���� �������� �Է��Ͻÿ�: ";
	cin >> pizza_slices;
	cout << "��� ���� �Է��Ͻÿ�: ";
	cin >> person;

	try
	{
		if (pizza_slices <= 0)
			throw "���ڼ��� �ʹ� �����ϴ�.";
		else if (person <= 0)
			throw "����� �����ϴ�!";

		slices_per_person = pizza_slices / person;

		cout << "�������� / �����: " << slices_per_person << endl;
	}
	catch(const char* e)
	{
		cout << e;
	}

	return 0;
}