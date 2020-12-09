#include <iostream>

using namespace std;

//싱글톤 : 객체가 한 개 이상 생성되지 않도록 강요하는 디자인패턴이다.
class SingleObject
{
	//객체가 생성되기 전에 접근해야하므로, static 멤버로 선언되야한다.
	static SingleObject* m_pInstance;

	SingleObject()
	{
	}
public:
	SingleObject* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new SingleObject();
		return m_pInstance;
	}
	void ShowMessage()
	{
		cout << "SingleTon" << endl;
	}
	void Release()
	{
		delete m_pInstance;
	}
};
SingleObject* SingleObject::m_pInstance = NULL;

int main(void)
{
	//SingleObject single; //생성자가 private라서 객체 생성 불가 따라서
	SingleObject* psingle = NULL;
	psingle = SingleObject::GetInstance();
	//컴파일 오류는 발생X, 그러나 객체가 생성되기 전에 사용하는 것은 명백히 문제가 된다. 
	//psingle = psingle->GetInstance();
	//객체가 생성되기 전에도 단순 함수의 호출이기 때문에 가능하다.
	//그러나 일반적으로는 멤버의 변수를 출력하기 때문에,
	//이러한 문법이 가능한 것도 문제가 발생한다.
	psingle->ShowMessage();
	psingle->Release();
	return 0;
}