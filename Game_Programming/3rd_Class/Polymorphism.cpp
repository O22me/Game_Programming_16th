#include <iostream>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace Inheritance;

void ShapeListMain()
{
	vector<Shape*> listShape;

	listShape.push_back(new Circle({ 0, 0 }, 5));
	listShape.push_back(new Rectangle({ 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 }));

}

void ShapeMain()
{
	//Shape cShape; //추상클래스는 실존하지 않으므로 실체화 불가능.
	Shape* 
	Circle cCircle({ 1, 1 }, 1);
}

int main()
{
	Inheritance::ShapeArrayMain();
	return 0;
}