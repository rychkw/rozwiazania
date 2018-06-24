#include "Kula.h"

double Kula::pole() {
    double pole = 4 * Kolo::pole();
    cout << "Pole: " << Kolo::pole() << endl;
    return pole;
}

double Kula::przekroj() {
    return Kolo::pole();
}