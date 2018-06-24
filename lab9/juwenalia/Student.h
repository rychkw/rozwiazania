#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include "Plecak.h"

class Student {
public:
    Student(){};
    Student(string plec , double weight, double drinking_period);
    ~Student(){};
    double BW; //0.58 for men lub 0.49 for women
    double masaCiala;
    double stalaMetab; //0.017;
    double czasPicia;
    Plecak plecak_studenta;
};

#endif //JIMP_EXERCISES_STUDENT_H
