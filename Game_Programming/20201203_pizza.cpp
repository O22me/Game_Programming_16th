#include <iostream>

using namespace std;

int main(void)
{
	int pizza_slices = 0;
	int person = -1;
	int slices_per_person = 0;

	cout << "피자 조각수를 입력하시오: ";
	cin >> pizza_slices;
	cout << "사람 수를 입력하시오: ";
	cin >> person;

	try
	{
		if (pizza_slices <= 0)
			throw "피자수가 너무 적습니다.";
		else if (person <= 0)
			throw "사람이 없습니다!";

		slices_per_person = pizza_slices / person;

		cout << "피자조각 / 사람수: " << slices_per_person << endl;
	}
	catch(const char* e)
	{
		cout << e;
	}

	return 0;
}