#include <iostream>
#include <string>//문자열객체 라이브러리

using namespace std;//전역에서 해당 네임스페이스를 이용함.(생략가능)

//네임스페이스: 전역에 구문들을 묶어서 사용하는 공간.
//std(standard): 표준함수가 정의되어있는 공간.(STL이나 문자열 등등...)
//외 다른이름으로 자신만의 함수를 정의하거나 커스터마이징이 가능하다.
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
//함수오버로딩: 같은 이름의 함수를 매개변수의 타입이나 갯수를 다르게 여러개 만드는것.
float Add(float a, float b, float c) { return (a + b + c); }
float Add(float a, float b) { return (a + b); }
//int Add(float a, float b, float c) { return (a + b + c); } //리턴값은 달라도 의미가 없음.
//인라인함수: 함수가 호출되지않고, 바로 수식으로 작성됨.
//(단, 컴파일러단에 결정되므로 선언한다고해서 모두적용되는것은 아님)
//디폴트매개변수: 매개변수를 지정하지않으면 지정된 값을 기본으로 초기화함.
//오버로딩하지않고 1개의 함수로 마치 3개의 함수를 정의한것처럼 사용가능하다.
inline int Add(int a = 0, int b = 0, int c = 0) { return (a + b + c); }
//inline int Add(int a = 0, int b, int c = 0) { return (a + b + c); } //중간을 비울수없다.
//inline int Add(int a = 0, int b, int c) { return (a + b + c); } //마지막 매개변수부터 채워야한다.

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
//참조자: 해당대상을 참조할수있는 변수.(포인터 대신 참조시 사용가능함.)
//매개변수에 주로 사용되고 다른용도로는 잘 사용되지않음.
//동적할당된 경우 반드시 포인터를 이용해야하고 참조로는 대처가 불가능함.
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
//이름과 성을 입력받아 선택한 국가 종류에 맞추어 풀네임을 만들어주는 프로그램
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
	//1. 각 문자접근하기
	for (int i = 0; strTest[i] != '\0'; i++)
		cout << strTest[i];
	cout << endl;
	//2. 문자열추가하기 -> 맨뒤
	strTest.append("test2");
	cout << "Append:" << strTest << endl;
	//3. 문자열삽입하기 -> 어디든상관없음.
	strTest.insert(0, "test1");
	cout << "Insert:" << strTest << endl;
	//4. 문자열찾기 -> 해당문자열찾기
	int idx = strTest.find("test2", 0);
	cout << "Find:" << idx << endl;
	//5. 문자열삭제하기
	strTest.erase(0, 4);
	cout << "Erase:" << strTest << endl;
	//6. stl과 비슷하다. 비어있는가? 뒤집기 비교
	cout << "==:" << (bool)(strTest == strTest) << endl;
	cout << "empty:" << strTest.empty() << endl;
	strTest.reserve();//배열의 크기가 불필요하게 할당되지않도록한다.
	//배열의크기가 변경되도록 준비되지않고, 
	//변경하지않는 문자열에 사용하면 효율적으로 관리할수있다.
	reverse(strTest[0], strTest[strTest.size() - 1]);
	cout << strTest << endl;
}
//다음과 같이 출력되는 단어 맞추기 게임만들기
//Q: _ _ _ _
//A: Z
//Z는 없는 문자입니다.
//Q: _ _ _ _
//A: G
//Q: G _ _ _
//A: A
//......
//Q: G A M _
//A: E
//Q: G A M E
//정답입니다!
//일반: 어떤 방법을 사용하든 문제 풀어보기
//심화: 위와 같은 문제를 문자열함수만 사용해서 풀어보기(ex. 배열접근x -> find)
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