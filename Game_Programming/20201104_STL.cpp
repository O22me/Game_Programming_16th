#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <hash_map>
using namespace std;
//벡터: 동적배열
//0.배열은 데이터가 저장될공간이 미리 확보되어있다.
//1.인덱스로 원소접근이 가능하다.
//2.각 자료는 포인터연산(인덱스)을 통한 순차/랜덤접근이 가능하다.
//3.배열의 크기를 런타임중에 변경가능하다.
void VectorMain()
{
	vector<int> container(1);//컨테이너생성시 크기를 지정가능하다.
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "] = " << container[i] << ",";
	cout << endl;
	container.resize(3); //배열의 크기를 지정한다.
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "] = " << container[i] << ",";
	cout << endl;
	//1.추가 2.삽입 3.삭제 4.모두삭제
	container.push_back(99); //추가
	//container.push_front(100); //배열은 앞을 추가하면 비효율적이다.
	container[1] = 20;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "] = " << container[i] << ",";
	cout << endl;
	vector<int>::iterator it = container.begin();//반복자: 원소에 접근하는것.
	cout << "begin+2:" << *(it + 2) << endl;//포인터연산을 이용하여 랜덤접근가능하다.
	//이터레이터 앞에 추가된다.(begin-> 첫번째원소가됨)
	container.insert(it, 39); //삽입할 노드를 모르는 경우는 배제한다.
	it = container.end();//end-> 마지막원소
	container.insert(it, 49); //삽입할 노드를 모르는 경우는 배제한다.
	//순차접근
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "] = " << *it << ",";
	cout << endl;
	it = container.begin();
	container.erase(it); //삭제
	container.pop_back(); //맨뒤삭제
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "] = " << *it << ",";
	container.clear(); //모두삭제
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "] = " << *it << ",";
}
//연결리스트
//1.데이터는 순차접근만 가능하다.(랜덤x)
//2.연결리스트에 추가,삽입,삭제은 O(1)이다.
//3.연결리스트의 종류: 단일, 환형, 이중 stl의 리스트는 어디에 해당되는가?
void ListMain()
{
	list<int> container(1);//컨테이너생성시 크기를 지정가능하다.
	list<int>::iterator it = container.begin();//반복자: 원소에 접근하는것.
	//1.추가 2.삽입 3.삭제 4.모두삭제
	container.push_back(99); //추가
	container.push_front(100);
	//container[1] = 20;
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	if (it == container.end()) cout << "it end!!" << endl;
	//끝에서 증가한다고 처음으로 돌아가지않으므로 환형은 아니다.
	it = container.begin();
	cout << "++begin:" << *(++it) << endl;//증가연산을 이용하여 다음원소에 접근가능하다.
	cout << "--(++begin):" << *(--it) << endl;//감소연산을 이용하여 이전원소에 접근가능.
	//즉, 이중연결리스트다.
	//이터레이터 앞에 추가된다.(begin-> 첫번째원소가됨)
	container.insert(it, 39); //삽입할 노드를 모르는 경우는 배제한다.
	it = container.end();//end-> 마지막원소
	container.insert(it, 49); //삽입할 노드를 모르는 경우는 배제한다.
	//순차접근
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = container.begin();
	container.pop_back(); //맨뒤원소 삭제
	container.pop_front();
	container.erase(it); //삭제
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	container.clear(); //모두삭제
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
}
//데크: 앞뒤로 자료를 추가/삭제가능, 랜덤접근가능.
void DequeMain()
{
	deque<int> container(1);//컨테이너생성시 크기를 지정가능하다.
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.resize(3); //배열의 크기를 지정한다.
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	//1.추가 2.삽입 3.삭제 4.모두삭제
	container.push_back(99); //추가
	container.push_front(100); //앞에도 추가가능하다.
	container[1] = 20;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	deque<int>::iterator it = container.begin();//반복자: 원소에 접근하는것.
	cout << "begin+2:" << *(it + 2) << endl;//포인터연산을 이용하여 랜덤접근가능하다.
	//이터레이터 앞에 추가된다.(begin-> 첫번째원소가됨)
	container.insert(it, 39); //삽입할 노드를 모르는 경우는 배제한다.
	it = container.end();//end-> 마지막원소
	container.insert(it, 49); //삽입할 노드를 모르는 경우는 배제한다.
	//순차접근
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = container.begin();
	container.pop_back(); //맨뒤원소 삭제
	container.pop_front(); //맨압원소 삭제
	it = container.begin();
	container.erase(it); //삭제
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	container.clear(); //모두삭제
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
}
//스택: 뒤에서 추가되고 뒤에서 꺼냄.
//재귀함수에서 이전 함수를 호출할때마다 스택에 쌓임.
//문자열뒤집기 -> 문자배열 -> apple -> elppa
void StackMain()
{
	char strApple[] = "apple";
	char strRevApple[6] = {};
	stack<char> stackReverse;

	for (int i = 0; strApple[i] != '\0'; i++)
		stackReverse.push(strApple[i]);
	int idx = 0;
	while (true)
	{
		strRevApple[idx] = stackReverse.top();
		stackReverse.pop();
		idx++;
		if (stackReverse.empty()) break;
	}

	cout << "Origin:" << strApple << endl;
	cout << "Reverse:" << strRevApple << endl;
}
//큐: 뒤에서 추가하고 앞에서 꺼냄.
//메세지큐: 이벤트가 발생한 순서대로 저장하는 공간.
//입력된 순서대로 명령어 처리하기
void QueueMain()
{
	queue<int> queMsg;
	int nInputMsg;
	cout << "InputMsg(exit:-1)" << endl;
	do
	{
		cin >> nInputMsg;
		if (nInputMsg == -1) break;
		queMsg.push(nInputMsg);
	} while (true);

	while (queMsg.empty() == false)
	{
		cout << queMsg.front() << endl;
		queMsg.pop();
	}
}
//우선순위큐: 우선순위가 높은 원소가 먼저나감(힙)
//무작위로 데이터를 넣었을때 어떤 순서대로 데이터가 나오는가? 큰값부터 나온다.
void PriorytyQueueMain()
{
	priority_queue<int> priorityQue;

	priorityQue.push(10);
	priorityQue.push(100);
	priorityQue.push(20);

	while (priorityQue.empty() == false)
	{
		cout << priorityQue.top() << endl;
		priorityQue.pop();
	}
}
//맵: 사전식으로 데이터를 찾을수있다.
//해당영어단어를 넣으면 한국어 결과가 나온다.
void MapMain()
{
	map<string, string> mapDic;

	mapDic["test"] = "시험";
	mapDic["pratice"] = "연습";
	mapDic["try"] = "도전";
	mapDic["note"] = "기록";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
//셋: 순서없이 데이터를 넣는다. 데이터는 순서와 상관없이 데이터를 찾는다.
void SetMain()
{
	set<int> setData;

	setData.insert(10);
	setData.insert(20);
	setData.insert(30);
	setData.insert(40);

	set<int>::iterator it = setData.find(10);

	if (it != setData.end()) it;
	for (it = setData.begin(); it != setData.end(); it++)
		cout << *it << ",";
	cout << endl;
}
//해시맵: 해시테이블
void HashMapMain()
{
	hash_map<string, string> mapDic;

	mapDic["test"] = "시험";
	mapDic["pratice"] = "연습";
	mapDic["try"] = "도전";
	mapDic["note"] = "기록";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
int main()
{
	VectorMain();
	//ListMain();
	//DequeMain();
	//StackMain();
	//QueueMain();
	//PriorytyQueueMain();
	//MapMain();
	//SetMain();
	return 0;
}