#ifndef Circle_h
#define Circle_h
#include "BasicShape.h"

class Circle: public Basicshape

{
private:

    int centerX=0;
    int centerY=0;
    int Radius=0;

public:
 Circle();
 Circle(int x, int y, int radius){centerX=x;centerY=y;Radius=radius;Area=Radius*Radius*3.14;Perimeter=Radius*2*3.14;}

int getcenterX(){return centerX;}
int getcenterY(){return centerY;}
int getRadius(){return Radius;}
void setcenterX(int x) {centerX=x;}
void setcenterY(int y){centerY=y;}
void setRadius(int radius){Radius = radius;}



   float getArea(){return Area;};
virtual float calcArea(){Area=Radius*Radius*3.14; return Area;} 
float getPerimeter();
virtual float calcPerimeter(){Perimeter=Radius*2*3.14; return Perimeter;} 
};

#endif // ENCRYPTION_H
