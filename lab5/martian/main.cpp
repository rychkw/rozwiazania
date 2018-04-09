
#include "Marsjanin.h"
#include <list>
#include <cstddef>

int main(){
    srand((int) time(NULL));
    std::list <Marsjanin> marsjanie;


    int i=0;
    while (i<100){
        if (Marsjanin::liczba < 5){
            cout<<"ukrycie\n";
        }else {
            if (Marsjanin::atak() == 1 && Marsjanin::liczba >= 5) {
                marsjanie.pop_back();
            }

        }
        int x = Marsjanin::atak();

        if (x==0) {
            cout<<"narodziny\n";
            Marsjanin *ptr = new Marsjanin;
            marsjanie.push_front(*ptr);
            Marsjanin::liczba++;
        }

        cout<<"mamy "<< Marsjanin::liczba<<" marsjan\n";
        i++;
    }

    return 0;
}

