//
// Created by sylwia on 05.03.18.
//
#include "DoubleBasePalindromes.h"
using namespace std;


int main(){
    int max;
    cout << "Podaj max, w jakim szukac double-base-palindromow: " << endl;
    cin >> max;
    if (max<1 || max>1000000){
        cout << "Podano bledny max. Wpisz jeszcze raz: ";
        cin >> max;
    }
    else{
        DoubleBasePalindromes(max);
    }
    return 0;
}