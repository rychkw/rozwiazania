//
// Created by kwiasylw on 06.03.18.
//

#include "Array2D.h"
using namespace std;

int main(){
    int rows, cols;
    cout << "Podaj liczbe wierszy tablicy: ";
    cin >> rows;
    cout << "\nPodaj liczbe kolumn tablicy: ";
    cin >> cols;
    (**Array2D)(rows, cols);
    return 0;
}