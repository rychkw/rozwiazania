//
// Created by sylwia on 05.03.18.
//
#include <iostream>
#include <string>
#include "Palindrome.h"

using namespace std;

int main(){
    int menu;
    string palindrome;
    cout << "MENU" << endl << "\t0 - Wyjscie" << endl << "\t1 - Sprawdz palindrom" << endl;
    cin >> menu;
    if (menu==0){
        return 0;
    }
    else if (menu==1){
        cin >> palindrome;
        if (is_palindrome(palindrome)){
            cout << "WYraz jest palindromem" << endl;
        }
        else{
            cout << "Wyraz nie jest palindromem" << endl;
        }
    }
    else{
        cout << "Wpisano zly numer" << endl << "Podaj jeszcze raz: ";
        cin >> menu;
    }
    return 0;
}