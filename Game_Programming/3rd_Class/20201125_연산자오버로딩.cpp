#include <iostream>
using namespace std;
//벡터
//속성: x,y
//동작: 더하기(이동하기),빼기(거리),곱하기(스칼라곱: 이동량을 곱함),평준화,스칼라

//다음과 같이 연산자오버로딩인 연산된 결과가 어떻게 되느냐에 따라서 리턴값이나 매개변수가 정해진다.
class Vector
{
	float x;
	float y;
public:
	Vector(float x = 0, float y = 0) //기본생성자
	{
		this->x = x;
		this->y = y;
	}
	Vector operator+(Vector vDist)
	{
		Vector vPos(x + vDist.x, y + vDist.y);
		return vPos;
	}
	Vector operator-(Vector vPos)
	{
		Vector vDist(x - vPos.x, y + vPos.y);
		return vDist;
	}
	Vector operator*(float fDist)
	{
		Vector vDist(x * fDist, y * fDist);
		return vDist;
	}
	float Scalar()
	{
		return  sqrtf(x * x + y * y);
	}
	Vector Normalize()
	{
		float fDist = Scalar();
		Vector vDir(x / fDist, y / fDist);
		return vDir;
	}
	void Display(const char* msg)
	{
		cout << msg << "(" << x << "," << y << ")" << endl;
	}
};

void VectorMain()
{
	Vector vPos;
	Vector vEndPos(1, 2);
	Vector vDist;

	vPos.Display("Pos");
	vEndPos.Display("EndPos");

	vDist = vEndPos - vPos;
	vEndPos = vPos + vDist;

	float fDist = vDist.Scalar();
	Vector vDir = vDist.Normalize();

	cout << "Dist:" << fDist << endl;
	vDir.Display("Dir");

	vDist.Display("Dist");
}

void main()
{
	VectorMain();
}