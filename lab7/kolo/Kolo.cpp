#include "Kolo.h"

Kolo::Kolo(double a, double b, double c)
{
    x = a;
    y = b;
    r = c;
}

double Kolo::pole() {
    return (3.14*r*r);
}