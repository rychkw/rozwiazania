#include "TinyUrl.h"

using namespace std;
using namespace tinyurl;


int main() {
    array<char, 6> CurrentHash = {'1','b','z','a','2','d'};
    NextHash(&CurrentHash);
    for (auto v : CurrentHash) {
        cout << v;
    }
    return 0;
}

