#include "Marsjanin.h"


int Marsjanin::liczba;

int Marsjanin::atak(){

    cout<<"atak\n";
    int zabity = std::rand()%2;

    if (zabity == 1 && Marsjanin::liczba>=5)
    {
        cout<<"zabity\n";
        Marsjanin::liczba--;
        return 1;
    }

    return 0;
}