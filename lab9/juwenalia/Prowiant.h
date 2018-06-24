//
// Created by miszk on 5/10/2017.
//

#ifndef JIMP_EXERCISES_PROWIANT_H
#define JIMP_EXERCISES_PROWIANT_H

#include <iostream>
#include "string"
using std::ostream;
using std::string;

class Prowiant {
public:
    int gram_alkoholu;
    string nazwa;
};

class Wodka : public Prowiant {
public:
    Wodka() {
        gram_alkoholu = 150;
        nazwa = "wodka";
    }

    ~Wodka(){};
};

class Piwko : public Prowiant {
public:
    Piwko() {
        gram_alkoholu = 25;
        nazwa = "piwko";
    }
    ~Piwko(){};
};

class Winko : public Prowiant{
public:
    Winko(){
        gram_alkoholu= 75;
        nazwa = "winko";
    }
    ~Winko(){};
};

class Sok : public Prowiant {
public:
    Sok(){
        gram_alkoholu = 0;
        nazwa = "sok";
    }
    ~Sok(){};
};

class Chipsy : public Prowiant{
public:
    Chipsy(){
        gram_alkoholu = 0;
        nazwa = "drozdzowka";
    }
    ~Chipsy(){};
};



#endif //JIMP_EXERCISES_PROWIANT_H
