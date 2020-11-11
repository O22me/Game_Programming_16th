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
	container.push_back(99);	 //push_back 또한 사이즈를 증가
	
	container.resize(5);			//size를 5로 재설정
	for (int i = 0; i < container.size(); i++) {
		cout << "[" << i << "] = " << container[i] << ",";
	}
	cout << endl;
	vector<int>::iterator it = container.begin();
	//이터레이터 : 노드에 포인터를 통해 해당 해당객체에 접근
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