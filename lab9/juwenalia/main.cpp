#include "Plecak.h"
#include "Student.h"
#include "WypelnijPlecak.h"
#include "PosortujProdukty.h"

int main ()
{
    int czas_imprezowania=12;
    int waga=80;
    string plec = "mezczyzna";

    cout<<"ile wazysz: ";
    std::cin>>waga;
    cout<<"kobieta czy mezczyzna (slownie): ";
    std::cin>>plec;
    cout<<"ile godzin zamierzasz impezowac:  ";
    std::cin>>czas_imprezowania;

    Student stud1{plec, waga, czas_imprezowania};
    WypelnijPlecak o(&stud1);


    int iter=1;
    std::cout << "WYPELNIONY PLECAK" <<std::endl;
     for (auto produkt : stud1.plecak_studenta.prowianty_)
    {
        std::cout<<iter<< ".  "<<produkt.get().nazwa<<std::endl;
        iter++;
    }

    PosortujProdukty yo(&stud1);

    iter = 1;
    std::cout << "POSORTOWANY PLECAK" <<std::endl;
    for (auto produkt : stud1.plecak_studenta.prowianty_)
    {
        std::cout<<iter<< ".  "<<produkt.get().nazwa<<""<<std::endl;
        iter++;
    }


    return 0;
}