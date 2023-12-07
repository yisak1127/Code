#ifndef BasicShape_h
#define BasicShape_h

class Basicshape
{
public:
    int Area=0;
    int Perimeter=0;

public:
   float getArea(){return Area;}
virtual float calcArea()=0;
float getPerimeter(){return Perimeter;}
virtual float calcPerimeter() =0;
};

#endif // ENCRYPTION_H
