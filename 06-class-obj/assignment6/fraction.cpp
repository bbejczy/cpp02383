#include "fraction.h"
#include <iostream>

fraction::fraction(int n, int d)
{
    this->numerator = n;
    this->denominator = d;
}

fraction::fraction(void)
{
    this->numerator = 0;
    this->denominator = 0;
}

fraction::~fraction()
{

}

void fraction::add(fraction f)
{
    // this->result_num = (this->numerator * f.denominator) + (f.numerator * this->denominator);
    // this->result_denom = (this->denominator * f.denominator);
    this->numerator = (this->numerator * f.denominator) + (f.numerator * this->denominator);
    this->denominator = (this->denominator * f.denominator);
}

void fraction::mult(fraction f)
{
    this->numerator = this->numerator * f.numerator;
    this->denominator = this->denominator * f.denominator;
}

void fraction::div(fraction f)
{
    this->numerator = this->numerator * f.denominator;
    this->denominator = this->denominator * f.numerator;
}

void fraction::display(void)
{
    int larger = 0;
    if (this->numerator>this->denominator){
        larger = this->numerator;
    }else{
        larger = this->denominator;
    }
    for(int i=2; i<=larger; i++){
        if((this->numerator%i==0)&(this->denominator%i==0)){
            this->numerator = (this->numerator/i);
            this->denominator = (this->denominator/i);
            break;
        }
    }
    cout << this->numerator << " / " << this->denominator << endl;
}