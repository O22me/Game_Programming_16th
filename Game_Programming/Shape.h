#pragma once

#include <iostream>
using namespace std;
//������ ���� �������� Ư¡�� �Ӽ��� ���� ���۸� �����ϴ� Ŭ������ ���� ��Ӱ���� �����ʿ䰡 ����.
namespace Inheritance
{
	//1�����̶�� ��ü�� ��������.
	struct s_Vector//��ü: ����(2���� ��ġ) : ��ǥ
	{
		//public: //����ü�� ��� �⺻������ public���� �����ȴ�.
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
		Shape() //������
		{
			cout << "Shape[" << this << "]" << endl;
		}
		//����Ҹ��� : �θ������Ϳ��� �Ҹ��ڰ� ȣ��Ǿ�� �� �ÿ� ���

		virtual ~Shape() 
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
		s_Vector vPos;
		float fRadius;
	public:
		Circle(s_Vector pos, float rad) //������
		{
			cout << "Circle[" << this << "]" << endl;
			vPos = pos;
			fRadius = rad;
			
			cout << "Rad:" << fRadius << endl;
		}
		~Circle() //�Ҹ���
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
		s_Vector vTL; //�»��
		s_Vector vTR; //����
		s_Vector vBL; //���ϴ�
		s_Vector vBR; //�»��
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

	//�θ��� �κа� �ڽ��� �κ��� �޸𸮰� �ٸ���. 
	//�ᱹ ����� ���ؼ� �ΰ��� �����̸��� �Լ��� ������.
	void ShapeMain()
	{
		Shape cShape;
		Circle cCircle({ 1, 1 }, 1);
		cShape.Draw();
		cShape.Shape::Draw();
		cCircle.Draw();
		cCircle.Shape::Draw();
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