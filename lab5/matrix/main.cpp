#include "Matrix.h"
#include <iostream>

using algebra::Matrix;

int main() {
    Matrix m1{{3.0i, 7. + 1.0i, 2.}, {5., 1.0i, 0.}, {0., 5., 1.0i}};
    Matrix m2{{7. + 1.0i, 0., 0.}, {0., 1.0i, 8.}, {15. + 2.0i, 0. + 3.0i, 4. + 2.0i}};

    cout << "Macierz pierwsza: " << m1.Print() << endl;
    cout << "Macierz druga: " << m2.Print() << endl;
    cout << "Sprawdz wartosc: " << m1.CheckValue(2, 2) << endl;
    cout << "Dodawanie" << (m1.Add(m2)).Print() << endl;
    cout << "Odejmowanie" << (m1.Sub(m2)).Print() << endl;
    cout << "Mnożenie" << (m1.Mul(m2)).Print() << endl;
    cout << "Mnożenie" << (m1.Mul(4)).Print() << endl;
    cout << "Dzielenie" << (m1.Div(2.)).Print() << endl;
    cout << "Potęgowanie" << (m1.Pow(2)).Print() << endl;
    cout << "Potęgowanie" << (m2.Pow(2)).Print() << endl;
    return 0;
}