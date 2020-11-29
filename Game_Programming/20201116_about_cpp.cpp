#include <iostream>
#include <string>//���ڿ���ü ���̺귯��

using namespace std;//�������� �ش� ���ӽ����̽��� �̿���.(��������)

//���ӽ����̽�: ������ �������� ��� ����ϴ� ����.
//std(standard): ǥ���Լ��� ���ǵǾ��ִ� ����.(STL�̳� ���ڿ� ���...)
//�� �ٸ��̸����� �ڽŸ��� �Լ��� �����ϰų� Ŀ���͸���¡�� �����ϴ�.
namespace A
{
	int g_nData;

	void PrintData()
	{
		cout << "A:" << g_nData << endl;
	}
}
namespace B
{
	int g_nData;

	void PrintData()
	{
		cout << "B:" << g_nData << endl;
	}
}

void NamespaceMain()
{
	A::g_nData = 100;
	A::PrintData();
	B::g_nData = 200;
	B::PrintData();
}
//�Լ������ε�: ���� �̸��� �Լ��� �Ű������� Ÿ���̳� ������ �ٸ��� ������ ����°�.
float Add(float a, float b, float c) { return (a + b + c); }
float Add(float a, float b) { return (a + b); }
//int Add(float a, float b, float c) { return (a + b + c); } //���ϰ��� �޶� �ǹ̰� ����.
//�ζ����Լ�: �Լ��� ȣ������ʰ�, �ٷ� �������� �ۼ���.
//(��, �����Ϸ��ܿ� �����ǹǷ� �����Ѵٰ��ؼ� �������Ǵ°��� �ƴ�)
//����Ʈ�Ű�����: �Ű������� �������������� ������ ���� �⺻���� �ʱ�ȭ��.
//�����ε������ʰ� 1���� �Լ��� ��ġ 3���� �Լ��� �����Ѱ�ó�� ��밡���ϴ�.
inline int Add(int a = 0, int b = 0, int c = 0) { return (a + b + c); }
//inline int Add(int a = 0, int b, int c = 0) { return (a + b + c); } //�߰��� ��������.
//inline int Add(int a = 0, int b, int c) { return (a + b + c); } //������ �Ű��������� ä�����Ѵ�.

void SwapVal(int a, int b) { int temp = a; a = b; b = temp; };
void SwapRef(int& a, int& b) { int temp = a; a = b; b = temp; };

void FunctionTestMain()
{
	cout << "#### Overload #####" << endl;
	cout << "floatAdd(3):" << Add(1.4f, 2.5f, 3.7f) << endl;
	cout << "floatAdd(2):" << Add(3.14f, 0.15f) << endl;
	cout << "#### Default Parameter ####" << endl;
	cout << "intAdd(3):" << Add(10, 20, 30) << endl;
	cout << "intAdd(2):" << Add(10, 20) << endl;
	cout << "intAdd(1):" << Add(10) << endl;
	cout << "intAdd(0):" << Add() << endl;
	cout << "#### Swap And Ref " << endl;
	int nDataA = 10; int nDataB = 20;
	SwapVal(nDataA, nDataB);
	cout << "SwapVal:" << nDataA << "/" << nDataB << endl;
	SwapRef(nDataA, nDataB);
	cout << "SwapRef:" << nDataA << "/" << nDataB << endl;
}
//������: �ش����� �����Ҽ��ִ� ����.(������ ��� ������ ��밡����.)
//�Ű������� �ַ� ���ǰ� �ٸ��뵵�δ� �� ����������.
//�����Ҵ�� ��� �ݵ�� �����͸� �̿��ؾ��ϰ� �����δ� ��ó�� �Ұ�����.
void RefMain()
{
	int nData = 10;
	int& refData = nData;

	cout << "1.Data[" << &nData << "]:" << nData << endl;
	cout << "1.refData[" << &refData << "]:" << refData << endl;
	nData = 20;
	cout << "2.Data[" << &nData << "]:" << nData << endl;
	cout << "2.refData[" << &refData << "]:" << refData << endl;
	refData = 30;
	cout << "3.Data[" << &nData << "]:" << nData << endl;
	cout << "3.refData[" << &refData << "]:" << refData << endl;
}
//�̸��� ���� �Է¹޾� ������ ���� ������ ���߾� Ǯ������ ������ִ� ���α׷�
void StringMain()
{
	string strFirstName, strLastName, strFullName;
	cout << "Input First/LastName:";
	cin >> strFirstName;
	cin >> strLastName;

	int nSelectType;
	cout << "SelectFullNameType(1:kr, 2:en):";
	cin >> nSelectType;
	switch (nSelectType)
	{
	case 1:
		cout << "kr-";
		strFullName = strLastName + strFirstName;
		break;
	case 2:
		cout << "en-";
		strFullName = strFirstName + strLastName;
		break;
	default:
		cout << "Type is null!!!" << endl;
		break;
	}
	cout << strFullName << endl;
}
void StringTestMain()
{
	string strTest = "Test";
	//1. �� ���������ϱ�
	for (int i = 0; strTest[i] != '\0'; i++)
		cout << strTest[i];
	cout << endl;
	//2. ���ڿ��߰��ϱ� -> �ǵ�
	strTest.append("test2");
	cout << "Append:" << strTest << endl;
	//3. ���ڿ������ϱ� -> ����������.
	strTest.insert(0, "test1");
	cout << "Insert:" << strTest << endl;
	//4. ���ڿ�ã�� -> �ش繮�ڿ�ã��
	int idx = strTest.find("test2", 0);
	cout << "Find:" << idx << endl;
	//5. ���ڿ������ϱ�
	strTest.erase(0, 4);
	cout << "Erase:" << strTest << endl;
	//6. stl�� ����ϴ�. ����ִ°�? ������ ��
	cout << "==:" << (bool)(strTest == strTest) << endl;
	cout << "empty:" << strTest.empty() << endl;
	strTest.reserve();//�迭�� ũ�Ⱑ ���ʿ��ϰ� �Ҵ�����ʵ����Ѵ�.
	//�迭��ũ�Ⱑ ����ǵ��� �غ�����ʰ�, 
	//���������ʴ� ���ڿ��� ����ϸ� ȿ�������� �����Ҽ��ִ�.
	reverse(strTest[0], strTest[strTest.size() - 1]);
	cout << strTest << endl;
}
//������ ���� ��µǴ� �ܾ� ���߱� ���Ӹ����
//Q: _ _ _ _
//A: Z
//Z�� ���� �����Դϴ�.
//Q: _ _ _ _
//A: G
//Q: G _ _ _
//A: A
//......
//Q: G A M _
//A: E
//Q: G A M E
//�����Դϴ�!
//�Ϲ�: � ����� ����ϵ� ���� Ǯ���
//��ȭ: ���� ���� ������ ���ڿ��Լ��� ����ؼ� Ǯ���(ex. �迭����x -> find)
void HangManMain()
{

}

void main()
{
	//NamespaceMain();
	//FunctionTestMain();
	//RefMain();
	//StringMain();
	StringTestMain();
}