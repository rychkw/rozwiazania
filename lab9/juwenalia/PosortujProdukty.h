#ifndef JIMP_EXERCISES_POSORTUJPRODUKTY_H
#define JIMP_EXERCISES_POSORTUJPRODUKTY_H

#include "Student.h"

class PosortujProdukty {
public:
    PosortujProdukty (Student *st);

    vector<reference_wrapper<Prowiant>> alkoholowe;

    vector<reference_wrapper<Prowiant>> bezalkoholowe;

    vector<reference_wrapper<Prowiant>> posortowane;

};


#endif //JIMP_EXERCISES_POSORTUJPRODUKTY_H
