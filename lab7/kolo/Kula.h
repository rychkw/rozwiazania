#ifndef JIMP_EXERCISES_KULA_H
#define JIMP_EXERCISES_KULA_H

#include "Kolo.h"
#include <iostream>

using namespace std;


class Kula : public Kolo {
    double z;

public:
    Kula(){};
    Kula(double x_, double y_, double z_, double r_) : Kolo (x_, y_, r_) {
        z = z_;
    };
    double pole();
    double przekroj();
};


#endif //JIMP_EXERCISES_KULA_Hk