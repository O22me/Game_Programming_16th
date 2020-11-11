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
//����: �����迭
//0.�迭�� �����Ͱ� ����ɰ����� �̸� Ȯ���Ǿ��ִ�.
//1.�ε����� ���������� �����ϴ�.
//2.�� �ڷ�� �����Ϳ���(�ε���)�� ���� ����/���������� �����ϴ�.
//3.�迭�� ũ�⸦ ��Ÿ���߿� ���氡���ϴ�.
void VectorMain()
{
	vector<int> container(1);//�����̳ʻ����� ũ�⸦ ���������ϴ�.
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.resize(3); //�迭�� ũ�⸦ �����Ѵ�.
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	//1.�߰� 2.���� 3.���� 4.��λ���
	container.push_back(99); //�߰�
	//container.push_front(100); //�迭�� ���� �߰��ϸ� ��ȿ�����̴�.
	container[1] = 20;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	vector<int>::iterator it = container.begin();//�ݺ���: ���ҿ� �����ϴ°�.
	cout << "begin+2:" << *(it + 2) << endl;//�����Ϳ����� �̿��Ͽ� �������ٰ����ϴ�.
	//���ͷ����� �տ� �߰��ȴ�.(begin-> ù��°���Ұ���)
	container.insert(it, 39); //������ ��带 �𸣴� ���� �����Ѵ�.
	it = container.end();//end-> ����������
	container.insert(it, 49); //������ ��带 �𸣴� ���� �����Ѵ�.
	//��������
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = container.begin();
	container.erase(it); //����
	container.pop_back(); //�ǵڻ���
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	container.clear(); //��λ���
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
}
//���Ḯ��Ʈ
//1.�����ʹ� �������ٸ� �����ϴ�.(����x)
//2.���Ḯ��Ʈ�� �߰�,����,������ O(1)�̴�.
//3.���Ḯ��Ʈ�� ����: ����, ȯ��, ���� stl�� ����Ʈ�� ��� �ش�Ǵ°�?
void ListMain()
{
	list<int> container(1);//�����̳ʻ����� ũ�⸦ ���������ϴ�.
	list<int>::iterator it = container.begin();//�ݺ���: ���ҿ� �����ϴ°�.
	//1.�߰� 2.���� 3.���� 4.��λ���
	container.push_back(99); //�߰�
	container.push_front(100);
	//container[1] = 20;
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	if (it == container.end()) cout << "it end!!" << endl;
	//������ �����Ѵٰ� ó������ ���ư��������Ƿ� ȯ���� �ƴϴ�.
	it = container.begin();
	cout << "++begin:" << *(++it) << endl;//���������� �̿��Ͽ� �������ҿ� ���ٰ����ϴ�.
	cout << "--(++begin):" << *(--it) << endl;//���ҿ����� �̿��Ͽ� �������ҿ� ���ٰ���.
	//��, ���߿��Ḯ��Ʈ��.
	//���ͷ����� �տ� �߰��ȴ�.(begin-> ù��°���Ұ���)
	container.insert(it, 39); //������ ��带 �𸣴� ���� �����Ѵ�.
	it = container.end();//end-> ����������
	container.insert(it, 49); //������ ��带 �𸣴� ���� �����Ѵ�.
	//��������
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = container.begin();
	container.pop_back(); //�ǵڿ��� ����
	container.pop_front();
	container.erase(it); //����
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	container.clear(); //��λ���
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
}
//��ũ: �յڷ� �ڷḦ �߰�/��������, �������ٰ���.
void DequeMain()
{
	deque<int> container(1);//�����̳ʻ����� ũ�⸦ ���������ϴ�.
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.resize(3); //�迭�� ũ�⸦ �����Ѵ�.
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	//1.�߰� 2.���� 3.���� 4.��λ���
	container.push_back(99); //�߰�
	container.push_front(100); //�տ��� �߰������ϴ�.
	container[1] = 20;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	deque<int>::iterator it = container.begin();//�ݺ���: ���ҿ� �����ϴ°�.
	cout << "begin+2:" << *(it + 2) << endl;//�����Ϳ����� �̿��Ͽ� �������ٰ����ϴ�.
	//���ͷ����� �տ� �߰��ȴ�.(begin-> ù��°���Ұ���)
	container.insert(it, 39); //������ ��带 �𸣴� ���� �����Ѵ�.
	it = container.end();//end-> ����������
	container.insert(it, 49); //������ ��带 �𸣴� ���� �����Ѵ�.
	//��������
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = container.begin();
	container.pop_back(); //�ǵڿ��� ����
	container.pop_front(); //�Ǿп��� ����
	it = container.begin();
	container.erase(it); //����
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	container.clear(); //��λ���
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
}
//����: �ڿ��� �߰��ǰ� �ڿ��� ����.
//����Լ����� ���� �Լ��� ȣ���Ҷ����� ���ÿ� ����.
//���ڿ������� -> ���ڹ迭 -> apple -> elppa
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
//ť: �ڿ��� �߰��ϰ� �տ��� ����.
//�޼���ť: �̺�Ʈ�� �߻��� ������� �����ϴ� ����.
//�Էµ� ������� ��ɾ� ó���ϱ�
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
//�켱����ť: �켱������ ���� ���Ұ� ��������(��)
//�������� �����͸� �־����� � ������� �����Ͱ� �����°�? ū������ ���´�.
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
//��: ���������� �����͸� ã�����ִ�.
//�ش翵��ܾ ������ �ѱ��� ����� ���´�.
void MapMain()
{
	map<string, string> mapDic;

	mapDic["test"] = "����";
	mapDic["pratice"] = "����";
	mapDic["try"] = "����";
	mapDic["note"] = "���";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
//��: �������� �����͸� �ִ´�. �����ʹ� ������ ������� �����͸� ã�´�.
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
//�ؽø�: �ؽ����̺�
void HashMapMain()
{
	hash_map<string, string> mapDic;

	mapDic["test"] = "����";
	mapDic["pratice"] = "����";
	mapDic["try"] = "����";
	mapDic["note"] = "���";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
void main()
{
	VectorMain();
	//ListMain();
	//DequeMain();
	//StackMain();
	//QueueMain();
	//PriorytyQueueMain();
	//MapMain();
	//SetMain();
}