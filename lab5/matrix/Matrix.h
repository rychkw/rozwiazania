#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <initializer_list>
#include <regex>

using std::cout;
using std::complex;
using std::endl;
using std::string;
using std::real;
using std::imag;
using std::pair;
using std::vector;
using std::initializer_list;
using std::regex;
using std::smatch;
using std::count;
using std::to_string;

namespace algebra{
    string doubleToString(double dou);
    complex<double> stringToComplex(string str);

    class Matrix{
        int cols;
        int rows;
        complex<double> **array;

    public:
        Matrix();
        Matrix(int rows_, int cols_);
        Matrix(const Matrix &matr);
        Matrix(string matlab);
        Matrix & operator=(const Matrix &pattern);
        ~Matrix();

        string Print() const;
        Matrix(initializer_list<vector<complex<double>>> list);
        pair<size_t, size_t> Size();
        complex<double> CheckValue(int row, int col);

        Matrix Add(const Matrix &matr) const;
        Matrix Sub(const Matrix &matr);
        Matrix Mul(const Matrix &matr);
        Matrix Mul(complex<double> value);
        Matrix Pow(int power);
        Matrix Div(complex<double> value);
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
