#include "Kula.h"
#include "Kolo.h"
#include <iostream>

using namespace std;

int main(){
    Kula k(0, 0, 0, 10);
    cout << "Pole powierzchni kuli: " << k.pole() << endl;
    cout << "Pole przekroju kuli: " << k.przekroj() << endl;
    return 0;
}