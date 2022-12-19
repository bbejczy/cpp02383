#include <iostream>
#include "cmath"
#include "shapes.h"


double Shape::area(){
    return this->h * this->w;
}

double Shape::perimeter(){
    return this->h*2+this->w*2;
}

double Shape::height(){
    return this->h;
}

double Shape::width(){
    return this->w;
}

void Shape::rotate(){
    double foo;
    foo = this->h;
    this->h = this->w;
    this->w = foo;
}

Rectangle::Rectangle(double h, double w){
    this->h=h;
    this->w=w;
}

Square::Square(double s){
    this->h = s;
    this->w = s;
}

Circle::Circle(double r){
    this->h = r*2;
    this->w = r*2;
}

double Circle::area(){
    return M_PI * pow(this->h/2, 2);
}

double Circle::perimeter(){
    return 2*M_PI*this->h/2;
}
