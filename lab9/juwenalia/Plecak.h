#ifndef JIMP_EXERCISES_PLECAK_H
#define JIMP_EXERCISES_PLECAK_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <string>
#include <stdexcept>
#include "Prowiant.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::reference_wrapper;



class Plecak {

public:
//to nie wiem czy poczebne
    Plecak(Prowiant &prowiant_) : prowiant{&prowiant_}{
        pojemnosc = 10;
        gram_alkoholu = 0;
    }

    Plecak() {
        pojemnosc = 20;
        gram_alkoholu = 0;
    }

    operator Prowiant&(){
        return *prowiant;
    }
    Prowiant *prowiant;
    int pojemnosc;
    int gram_alkoholu;
   vector<reference_wrapper<Prowiant>> prowianty_;

};


#endif //JIMP_EXERCISES_PLECAK_H
