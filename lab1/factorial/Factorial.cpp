//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int Factorial(int value) {
    if (value>12 || value<-12)
        return 0;
    if (value>1)
        return value* Factorial(value - 1);
    else if (value==1)
        return 1;
    else if (value==0)
        return 1;
    else
        return value* Factorial(value + 1);
}
