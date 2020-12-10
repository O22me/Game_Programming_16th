#include <iostream>

using namespace std;

//�̱��� : ��ü�� �� �� �̻� �������� �ʵ��� �����ϴ� �����������̴�.
class SingleObject
{
	//��ü�� �����Ǳ� ���� �����ؾ��ϹǷ�, static ����� ����Ǿ��Ѵ�.
	static SingleObject* m_pInstance;

	SingleObject()
	{
	}
public:
	static SingleObject* GetInstance() //static ������ ���� ��ü�������� �Լ� ������ �Ͽ���.
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
	//SingleObject single; //�����ڰ� private�� ��ü ���� �Ұ� ����
	SingleObject* psingle = NULL;
	psingle = SingleObject::GetInstance();
	//������ ������ �߻�X, �׷��� ��ü�� �����Ǳ� ���� ����ϴ� ���� ����� ������ �ȴ�. 
	//psingle = psingle->GetInstance();
	//��ü�� �����Ǳ� ������ �ܼ� �Լ��� ȣ���̱� ������ �����ϴ�.
	//�׷��� �Ϲ������δ� ����� ������ ����ϱ� ������,
	//�̷��� ������ ������ �͵� ������ �߻��Ѵ�.
	psingle->ShowMessage();
	psingle->Release();
	return 0;
}