//
// Created by sylwia on 05.03.18.
//
#include "ReverseString.h"
using namespace std;

int main(){
    string word;
    cout << "Wpisz slowo do odwrocenia: " << endl;
    cin >> word;
    cout << "Odwrocone slowo: " << reverse(word);
    return 0;
}
