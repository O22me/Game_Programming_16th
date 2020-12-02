#pragma once

#include <iostream>
using namespace std;
//도형과 같이 공통적인 특징이 속성이 없고 동작만 존재하는 클래스를 굳이 상속관계로 만들필요가 없다.
namespace Inheritance
{
	//1차원이라면 객체로 볼수없다.
	struct s_Vector//객체: 벡터(2차원 위치) : 좌표
	{
		//public: //구조체의 경우 기본적으로 public으로 설정된다.
		float x;
		float y;
		void Print(const char* msg)
		{
			cout << msg << "(" << x << "," << y << ")" << endl;
		}
	};
	//추상클래스 : 순수가상함수를 1개 이상 가진 함수
	class Shape //도형:
	{
	public:
		Shape() //생성자
		{
			cout << "Shape[" << this << "]" << endl;
		}
		~Shape() //소멸자
		{
			cout << "~Shape[" << this << "]" << endl;
		}
		//가상함수 : 실제 구현이 상속받은 자식에서 함수의 기능이 결정되는것.
		//순수가상함수 : 해당 함수의 구현이 반드시 자식함수에서 구현되어야 함.
		virtual void Draw() // = 0			를 붙이면 순수가상함수
		{
			cout << "Shape[" << this << "]::Draw()" << endl;
		};
	};
	//원과 같이 삼각형,사각형을 클래스로 만들기
	//실체화: 추상클래스를 상속받아 구현하는 클래스 (존재하지 않는 shape의 형태를 상속을 통해서 지정하는 것.
	class Circle : public Shape
	{
		s_Vector vPos;
		float fRadius;
	public:
		Circle(s_Vector pos, float rad) //생성자
		{
			cout << "Circle[" << this << "]" << endl;
			vPos = pos;
			fRadius = rad;
			
			cout << "Rad:" << fRadius << endl;
		}
		~Circle() //소멸자
		{
			cout << "~Circle[" << this << "]()" << endl;
		}
		//가상함수를 자식객체에서 구현하지 않으면 부모의 클래스를 호출한다.
		//그러나 shape에서는 Draw가 존재할 수 없으므로 이러한 문법이 허용되서는 안된다.
		//순수가상함수를 사용할 경우 자식 객체에서 반드시 구현해야 컴파일가능.
		void Draw()
		{
			cout << "Circle[" << this << "]::Draw()" << endl;
			vPos.Print("Pos");
			cout << "Rad:" << fRadius << endl;
		}
	};
	class Triangle : public Shape
	{
		s_Vector vA;
		s_Vector vB;
		s_Vector vC;
	public:
		Triangle(s_Vector a, s_Vector b, s_Vector c)
		{
			cout << "Triangle[" << this << "]" << endl;
			vA = a;
			vB = b;
			vC = c;
		}
		~Triangle()
		{ 
			cout << "Triangle[" << this << "]" << endl; 
		}
		void Draw()
		{
			cout << "Rectaangle[" << this << "]::Draw()" << endl;
			vA.Print("A:");
			vB.Print("B:");
			vC.Print("C:");
		}
	};
	class Rectangle : public Shape
	{
		s_Vector vTL; //좌상단
		s_Vector vTR; //우상단
		s_Vector vBL; //좌하단
		s_Vector vBR; //좌상단
	public:
		Rectangle(s_Vector tl, s_Vector tr, s_Vector bl, s_Vector br)
		{
			cout << "Rectangle[" << this << "]" << endl;
			vTL = tl;
			vTR = tr;
			vBL = bl;
			vBR = br;
		}
		~Rectangle()
		{
			cout << "~Rectangle[" << this << "]()" << endl;
		}
		void Draw()
		{
			cout << "RectAangle[" << this << "]::Draw()" << endl;
			vTL.Print("TopLeft:");
			vTR.Print("TopRight:");
			vBL.Print("BottomLeft:");
			vBR.Print("BottomRight:");
		}
	};

	//부모의 부분과 자식의 부분은 메모리가 다르다. 
	//결국 상속을 통해서 두개의 같은이름의 함수를 가진다.
	void ShapeMain()
	{
		Shape cShape;
		Circle cCircle({ 1, 1 }, 1);
		cShape.Draw();
		cShape.Shape::Draw();
		cCircle.Draw();
		cCircle.Shape::Draw();
	}
	//프로그램 실행중에 선택하여 모양을 여러개를 그리려면 어떻게해야하는가?//동적으로 메모리를 할당받아야한다.
	void ShapeArrayMain()
	{
		Shape* arrShape[3];

		arrShape[0] = new Circle({ 0, 0 }, 5);
		arrShape[1] = new Rectangle({ 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 });
		arrShape[2] = new Triangle({ 0, 0 }, { 0, 1 }, { 1, 0 });

		for (int i = 0; i < 3; i++)
		{
			arrShape[i]->Draw();
		}
	}
}