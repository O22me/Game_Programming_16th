#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

void VectorMain() {
	vector<int> container(3, 7);
	container[0] = 10;
	for (int i = 0; i < container.size(); i++) {
		cout << "[" << i << "] = " << container[i] << ",";
	}
	cout << endl;
	container.push_back(99);	 //push_back ���� ����� ����
	
	container.resize(5);			//size�� 5�� �缳��
	for (int i = 0; i < container.size(); i++) {
		cout << "[" << i << "] = " << container[i] << ",";
	}
	cout << endl;
	vector<int>::iterator it = container.begin();
	//���ͷ����� : ��忡 �����͸� ���� �ش� �ش簴ü�� ����
	cout << "begin + 3 = " << *(it + 3) << endl;

	container.insert(it, 29);
	for (it = container.begin(); it != container.end(); it++) {
		cout << "[" << &*it << "] = " << *it << ",";
	}
	cout << endl;
	it = container.begin();
	container.erase(it + 1);
	container.pop_back();
	for (int i = 0; i < container.size(); i++) {
		cout << "[" << i << "] = " << container[i] << ",";
	}
	cout << endl;
	container.clear();
	for (int i = 0; i < container.size(); i++) {
		cout << "[" << i << "] = " << container[i] << ",";
	}
	cout << endl;
}
void ListMain() {
	list<int> container(4, 7);
	
	cout << endl;
}

int main(void) {
	VectorMain();
	//ListMain();
	return 0;
}