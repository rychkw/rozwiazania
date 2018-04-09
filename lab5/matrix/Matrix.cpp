#include "Matrix.h"

using algebra::Matrix;


//konstruktor bezparametrowy
Matrix::Matrix() : rows(0), cols(0) {}


//konstruktor parametrowy
Matrix::Matrix(int rows_, int cols_) {
    rows = rows_;
    cols = cols_;
    if ((rows_ < 0) || (cols_ < 0)) {
        cout << "Wartosci nie moga byc ujemne";
    }
    array = new complex<double> *[rows_];
    for (int i = 0; i < rows_; i++) {
        array[i] = new complex<double>[cols_];
    }
}


//konstruktor kopiujacy
Matrix::Matrix(const Matrix &matr) {
    rows = matr.rows;
    cols = matr.cols;

    array = new complex<double> *[rows]; //tworzenie nowej tablicy
    for (int i = 0; i < rows; ++i) {
        array[i] = new complex<double>[cols];
        for (int j = 0; j < cols; j++) {
            array[i][j] = matr.array[i][j];
        }
    }
}


complex<double> algebra::stringToComplex(string str) {
    string real = str.substr(0, str.find('i'));
    string im = str.substr(str.find('i') + 1, str.length());
    double r = stod(real);
    double i = stod(im);
    complex<double> comp;
    comp.real(r);
    comp.imag(i);
    return comp;
}


Matrix::Matrix(string matlab) {
    long semicolons = count(matlab.begin(), matlab.end(), ';');
    rows = int(semicolons) + 1;

    string part = matlab.substr(0, matlab.find(';'));
    long spaces = count(part.begin(), part.end(), ' ');
    cols = int(spaces) + 1;

    auto **tab = new complex<double> *[rows];
    for (int i = 0; i < rows; i++)
        tab[i] = new complex<double>[cols];
    array = tab;

    string line;
    line = matlab.substr(1, matlab.length() - 2);
    regex regex{R"(\w+\.*\w+\.*\w+)"};
    smatch matches;

    int row = 0, col = 0;
    while (regex_search(line, matches, regex)) {
        for (auto m : matches) {
            string x = m.str();
            array[row][col] = stringToComplex(x);
            col++;
            if (col > cols - 1) {
                col = 0;
                row++;
            }
        }
        line = matches.suffix().str();
    }
}


//operator przypisania kopiujacy
Matrix &Matrix::operator=(const Matrix &pattern) {
    if (this != &pattern) {
        for (int i = 0; i < this->rows; i++) {
            delete[] array[i];
        }
        delete[] array;

        rows = pattern.rows;
        cols = pattern.cols;
        auto **tab = new complex<double> *[rows];
        for (int i = 0; i < rows; i++) {
            tab[i] = new complex<double>[cols];
        }
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < cols; j++) {
                tab[i][j] = pattern.array[i][j];
            }
        }
    }
    return *this;
}

//destruktor
Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}


string algebra::doubleToString(double dou) {
    string strDou = to_string(dou);
    for (int i = int(strDou.length()) - 1; i >= 0; i--) {
        if (strDou[i] != '0') {
            break;
        }
        else {
            strDou = strDou.substr(0, strDou.length() - 1);
        }
    }
    if (strDou[strDou.length() - 1] == '.') {
        strDou = strDou.substr(0, strDou.length() - 1);
    }
    return strDou;
}


string Matrix::Print() const {
    if (cols == 0) {
        return "[]";
    }
    string ret = "[";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ret += (doubleToString(array[i][j].real()) + "i" + doubleToString(array[i][j].imag()));
            if (j != cols - 1)
                ret += ", ";
        }
        if (i != rows - 1) {
            ret += "; ";
        }
    }
    ret += "]";
    return ret;
}


Matrix::Matrix(initializer_list<vector<complex<double>>> list) {
    int rowNumb = int(list.size());
    long colNumb = 0;
    for (auto &row : list) {
        colNumb = row.size();
        break;
    }

    rows = rowNumb;
    cols = int(colNumb);

    auto **tab = new complex<double> *[rows];
    for (int i = 0; i < rows; i++) {
        tab[i] = new complex<double>[cols];
    }
    array = tab;
    array[0][0] = 1.0 + 1.0i;


    int i = 0, j = 0;
    for (vector<complex<double>> row : list) {
        j = 0;
        for (complex<double> element : row) {
            array[i][j] = element;
            j++;
        }
        i++;
    }
}


pair<size_t, size_t> Matrix::Size() {
    return pair<size_t, size_t> {rows, cols};
}


complex<double> Matrix::CheckValue(int row, int col) {
    return array[row][col];
}


Matrix Matrix::Add(const Matrix &matr) const {
    if ((rows == matr.rows) && (cols == matr.cols)) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.array[i][j] = array[i][j] + matr.array[i][j];
            }
        }
        return result;
    }
    else {
        return Matrix();
    }
}


Matrix Matrix::Sub(const Matrix &matr) {
    if ((rows == matr.rows) && (cols == matr.cols)) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.array[i][j] = array[i][j] - matr.array[i][j];
            }
        }
        return result;
    }
    else {
        return Matrix();
    }
}


Matrix Matrix::Mul(const Matrix &matr) {
    if (cols == matr.rows) {
        Matrix result(rows, matr.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < matr.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.array[i][j] += array[i][k] * matr.array[k][j];
                }
            }
        }
        return result;
    }
    else {
        Matrix result(0, 0);
        return result;
    }
}


Matrix Matrix::Mul(complex<double> value) {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.array[i][j] = array[i][j] * value;
        }
    }
    return result;
}


Matrix Matrix::Pow(int power) {
    Matrix result(*this);
    if (power == 0) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == j) {
                    result.array[i][j] = 1;
                }
                else {
                    result.array[i][j] = 0;
                }
            }
        }
        return result;
    }
    else {
        for (int i = 2; i <= power; i++) {
            result = result.Mul(*this);
        }
        return result;
    }
}


Matrix Matrix::Div(complex<double> value) {
    if (value != 0.) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.array[i][j] = array[i][j] / value;
            }
        }
        return result;
    }
    else {
        Matrix result(0, 0);
        return result;
    }
}