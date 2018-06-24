#ifndef JIMP_EXERCISES_WYPELNIJPLECAK_H
#define JIMP_EXERCISES_WYPELNIJPLECAK_H

#include "Student.h"
#include "Prowiant.h"

class WypelnijPlecak {
public:
    WypelnijPlecak(Student *imprezowicz);
    ~WypelnijPlecak(){};

    bool ebac(Plecak pl, Student st, int dodatkowe_gramy_alkoholu);
};


#endif //JIMP_EXERCISES_WYPELNIJPLECAK_H
