#include "Iterable.h"

using namespace utility;

int main() {
    const vector<int> vi {4, 77, -91};
    const vector<string> vs {"4", "9991", "adfskld"};

    for (const auto &p : Zipper(vi, vs)) {
        cout << "(" << p.first << ", \"" << p.second << "\") ";
    }
    //wypisze: (4, "4") (77, "9991") (-91,"adfskld")

    for (const auto &p : Enumerate(vs)) {
        cout << "(" << p.first << ", \"" << p.second << "\") ";
    }
    //wypisze: (0, "4") (1, "9991") (2,"adfskld")

    for (const auto &p : Product(vi,vs)) {
        cout << "(" << p.first << ", \"" << p.second << "\") ";
    }
    //wypisze: (4, "4") (4,"9991") (4, "adfskld") (77, "4") (77,"9991") (77, "adfskld") (-91,"4") (-91,"9991") (-91, "adfskld")

    return 0;
}
