#include "Rational.hh"
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}
Rational::Rational() : numerator{0}, denominator{1} {}
Rational::Rational(int numerator) : numerator{numerator}, denominator{1} {}
Rational::Rational(int num, int denom)
{
    int divisor = gcd(num, denom);
    denominator = denom / divisor;
    numerator = num / divisor;
    if (denominator < 0)
    {
        denominator = denominator * -1;
        numerator = numerator * -1;
    };
}
void Rational::print()
{
    cout << "Numerator: " << numerator << " "
         << "Denominator: " << denominator << "\n";
}
Rational Rational::operator+(Rational &j)
{
    int denom = j.denominator * this->denominator;
    int x = j.numerator * this->denominator;
    int y = this->numerator * j.denominator;
    return Rational{(x + y), denom};
}
Rational Rational::operator-(Rational j)
{
    j.denominator = j.denominator * -1;
    return *this + j;
}
Rational Rational::operator*(Rational &j)
{
    int a = this->numerator * j.numerator;
    int b = this->denominator * j.denominator;
    return Rational(a, b);
}
Rational Rational::operator/(Rational &j)
{
    Rational inverse{j.denominator, j.numerator};
    return *this * inverse;
}

void Rational::operator+=(Rational &j)
{
    *this = *this + j;
}
void Rational::operator-=(Rational &j)
{
    *this = *this - j;
}

Rational Rational::operator-()
{
    return Rational{this->numerator * -1, this->denominator};
}
Rational Rational::recip()
{
    return Rational{this->denominator, this->numerator};
}

ostream &operator<<(ostream &os, Rational &r)
{
    os << r.numerator << "/" << r.denominator;
    return os;
}

istream &operator>>(istream &in, Rational &r)
{
    string s;
    in >> s;
    int pos = s.find("/");
    int num = stoi(s.substr(0, pos));
    int denom = stoi(s.substr(pos + 1, s.length()));
    Rational tmp{num, denom};
    r = tmp;
    return in;
}

bool Rational::operator==(Rational &j)
{
    return (this->denominator == j.denominator && this->numerator == j.numerator);
}

bool Rational::operator>(Rational &j)
{
    int thisnum = this->numerator * j.denominator;
    int jnum = j.numerator * this->denominator;
    return thisnum > jnum;
}

bool Rational::operator<(Rational &j)
{
    return !(*this > j);
}

bool Rational::operator>=(Rational &j)
{
    return *this == j || *this > j;
}
bool Rational::operator<=(Rational &j)
{
    return *this == j || *this < j;
}