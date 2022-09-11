#include "Rational.hh"
void testRational()
{
    Rational r{15, -3}; // -5
    Rational r1{10, 1}; // 10
    printf("+ \n");
    (r + r1).print();
    r1.print();

    printf("- \n");
    (r - r1).print();
    r1.print();

    printf("* \n");
    (r * r1).print();

    printf("/ \n");
    (r / r1).print();

    printf("+= \n");
    r.print();
    r += r1;
    r.print();

    printf("Console input \n");
    Rational r2;
    cin >> r2;
    r2.print();
};

int main()
{
    testRational();
};
