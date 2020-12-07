#include <iostream>

using namespace std;

template<typename Type>
void Swap(Type& a, Type& b)
{
	Type temp = a;
	a = b;
	b = a;
}
void FunctionTempletMain()
{
	int nDataA = 10;
	int nDataB = 20;
	float fDataA = 3.14f;
	float fDataB = 0.1f;

	Swap(nDataA, nDataB);
	Swap(fDataA, fDataB);
}
template<typename Type>
class Box
{
	Type data;
public:
	void SetData(Type data) { this->data = data; }
	Type GetData() { return data; }
	void Display()
	{
		cout << typeid(*this).name() << "(" << typeid(data).name() << "):" << data << endl;
	}
};

template <typename TypeKey, typename TypeData>
class MapData
{
	TypeKey key;
	TypeData data;
public:
	MapData(TypeKey key, TypeData data)
	{
		this->key = key;
		this->data = data;
	}
	TypeData operator[](TypeKey) { return data; }
};
void TempletClassMain()
{
	Box<int> box;
	box.SetData(10);
	box.Display();

	MapData<std::string, float> data("Pi", 3.14f);
	cout << data["Pi"] << endl;
}
void main()
{
	FunctionTempletMain();
	TempletClassMain();
}