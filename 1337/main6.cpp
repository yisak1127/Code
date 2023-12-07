// yisak worku yxw190038
#include <iostream>
#include "BasicShape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

void BasicShape(Basicshape* b1)
{
    cout<<b1->getArea()<<endl;
    cout<<b1->getPerimeter()<<endl;
}

int main()
{
    Circle c1(0, 0, 5);
    Rectangle r1(3, 4);
    BasicShape(&c1);
    BasicShape(&r1);
}