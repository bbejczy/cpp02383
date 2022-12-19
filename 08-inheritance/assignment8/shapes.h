#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
public:
    double h;
    double w;
    virtual double area();
    virtual double perimeter();
    double height();
    double width();
    void rotate();
};

class Rectangle : public Shape{
public:
    Rectangle(double h, double w);
};

class Square : public Shape{
public:
    Square(double s);
};

class Circle : public Shape{
public:
    Circle(double r);
    double area();
    double perimeter();
};

#endif /* SHAPE_H_ */