#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <numeric>
using namespace std;

namespace factoryMethod{
    template <class T1>
    T1 Create(){
        return T1();
    }

    class MyType{
    public:
        std::string SayHello(){
            return "hello";
        }
    };
}


template<class T1>
T1 Sum( const T1 &left, const T1 &right) {
    return left + right;
}


template<class T2>
T2 Mean(std::vector<T2> v){
    T2 suma = std::accumulate(v.begin(), v.end(), T2());
    T2 rozmiar = v.size();
    T2 wynik = suma/rozmiar;
    return wynik;
}


template<class T3>
auto Value(const T3 &wsk){
    return *wsk;
}



#endif //JIMP_EXERCISES_FACTORYMETHOD_H