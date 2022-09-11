#ifndef RATIONAL_HH
#define RATIONAL_HH
#include <iostream>
using namespace std;
class Rational
{
public:
    int numerator;
    int denominator;
    Rational();
    Rational(int numerator);
    Rational(int num, int denom);
    void print();
    Rational operator+(Rational &j);
    Rational operator-(Rational j);
    Rational operator*(Rational &j);
    Rational operator/(Rational &j);
    Rational operator-();
    Rational recip();
    void operator+=(Rational &j);
    void operator-=(Rational &j);
    bool operator==(Rational &j);
    bool operator>(Rational &j);
    bool operator<(Rational &j);
    bool operator>=(Rational &j);
    bool operator<=(Rational &j);
    friend ostream &operator<<(ostream &os, Rational &r);
    friend istream &operator>>(istream &in, Rational &r);
};
#endif
