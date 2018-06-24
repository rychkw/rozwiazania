#include <FactoryMethod.h>
#include <iostream>
using namespace std;

int main(){
    int i=factoryMethod::Create<int>();
    int a=4;
    int b=3;
    int c=Sum(a,b);
    cout << c <<endl;

    double d=4.5;
    auto e=Sum(2.,d);
    cout << e << endl;
    return 0;
}