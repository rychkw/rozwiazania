
#include "Student.h"
Student::Student(string plec, double weight, double drinking_period) {
    if(plec == "mezczyzna")
        BW = 0.58;
    else if(plec == "kobieta")
        BW = 0.46;
    else
        throw std::invalid_argument("Co to za plec?!");

    masaCiala = weight;
    czasPicia = drinking_period;
    stalaMetab = 0.015;
}