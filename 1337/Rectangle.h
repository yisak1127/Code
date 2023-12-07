#ifndef Rectangle_h
#define Rectangle_h
#include "BasicShape.h"

class Rectangle: public Basicshape

{
private:

    int width=0;
    int length=0;

public:
 Rectangle();
 Rectangle(int w, int l){width=w; length=l;Area=length*width;Perimeter=length*2+width*2;}

int getwidth(){return width;};
int getlength(){return length;};
void setwidth(int w){width=w;};
void setlength(int l){length=l;};



   float getArea(){return Area;}
virtual float calcArea(){ Area=length*width; return Area;}
float getPerimeter(){return Perimeter;}
virtual float calcPerimeter(){Perimeter=length*2+width*2; return Perimeter; }
};

#endif // ENCRYPTION_H
