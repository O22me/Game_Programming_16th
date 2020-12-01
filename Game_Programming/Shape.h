#pragma once

#include <iostream>
using namespace std;
//������ ���� �������� Ư¡�� �Ӽ��� ���� ���۸� �����ϴ� Ŭ������ ���� ��Ӱ���� �����ʿ䰡 ����.
namespace Inheritance
{
	//1�����̶�� ��ü�� ��������.
	struct Vector//��ü: ����(2���� ��ġ)
	{
		//public:
		float x;
		float y;
		void Print(const char* msg)
		{
			cout << msg << "(" << x << "," << y << ")" << endl;
		}
	};
	//�߻�Ŭ���� : ���������Լ��� 1�� �̻� ���� �Լ�
	class Shape //����:
	{
	public:
		Shape()
		{
			cout << "Shape[" << this << "]" << endl;
		}
		~Shape()
		{
			cout << "~Shape[" << this << "]" << endl;
		}
		//�����Լ� : ���� ������ ��ӹ��� �ڽĿ��� �Լ��� ����� �����Ǵ°�.
		//���������Լ� : �ش� �Լ��� ������ �ݵ�� �ڽ��Լ����� �����Ǿ�� ��.
		virtual void Draw() // = 0			�� ���̸� ���������Լ�
		{
			cout << "Shape[" << this << "]::Draw()" << endl;
		};
	};
	//���� ���� �ﰢ��,�簢���� Ŭ������ �����
	//��üȭ: �߻�Ŭ������ ��ӹ޾� �����ϴ� Ŭ���� (�������� �ʴ� shape�� ���¸� ����� ���ؼ� �����ϴ� ��.
	class Circle : public Shape
	{
		Vector vPos;
		float fRadius;
	public:
		Circle(Vector pos, float rad)
		{
			cout << "Circle[" << this << "]" << endl;
			vPos = pos;
			fRadius = rad;
			
			cout << "Rad:" << fRadius << endl;
		}
		~Circle()
		{
			cout << "~Circle[" << this << "]()" << endl;
		}
		//�����Լ��� �ڽİ�ü���� �������� ������ �θ��� Ŭ������ ȣ���Ѵ�.
		//�׷��� shape������ Draw�� ������ �� �����Ƿ� �̷��� ������ ���Ǽ��� �ȵȴ�.
		//���������Լ��� ����� ��� �ڽ� ��ü���� �ݵ�� �����ؾ� �����ϰ���.
		void Draw()
		{
			cout << "Circle[" << this << "]::Draw()" << endl;
			vPos.Print("Pos");
			cout << "Rad:" << fRadius << endl;
		}
	};
	class Triangle : public Shape
	{
		Vector vA;
		Vector vB;
		Vector vC;
	public:
		Triangle(Vector a, Vector b, Vector c) { cout << "TriAngle[" << this << "]" << endl; };
		~Triangle() { cout << "TriAngle[" << this << "]" << endl; };
		void Draw()
		{
			cout << "RectAangle[" << this << "]::Draw()" << endl;
			vA.Print("A:");
			vB.Print("B:");
			vC.Print("C:");
		}
	};
	class Rectangle : public Shape
	{
		Vector vTL;
		Vector vTR;
		Vector vBL;
		Vector vBR;
	public:
		Rectangle(Vector tl, Vector tr, Vector bl, Vector br)
		{
			cout << "RectAangle[" << this << "]" << endl;
			vTL = tl;
			vTR = tr;
			vBL = bl;
			vBR = br;
		}
		~Rectangle()
		{
			cout << "~RectAangle[" << this << "]()" << endl;
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

	//�θ��� �κа� �ڽ��� �κ��� �޸𸮰� �ٸ���. 
	//�ᱹ ����� ���ؼ� �ΰ��� �����̸��� �Լ��� ������.
	void ShapeMain()
	{
		Shape cShape;
		Circle cCrilce({ 1,1 }, 1);
		cShape.Draw();
		cShape.Shape::Draw();
		cCrilce.Draw();
		cCrilce.Shape::Draw();
	}
	//���α׷� �����߿� �����Ͽ� ����� �������� �׸����� ����ؾ��ϴ°�?//�������� �޸𸮸� �Ҵ�޾ƾ��Ѵ�.
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