//
// Created by kwiasylw on 13.03.18.
//

#include "MinimalTimeDifference.h"
#include <iostream>
using namespace std;
using namespace minimaltimedifference;
vector <string> times {"00:00", "12:12", "13:13", "8:55", "17:01", "00:02"};


int main() {
    for (string time : times) {
        cout << time << ", ";
    }
    cout << "\nNajmniejsza roznica czasow to: " << MinimalTimeDifference(times) << " minuty\n";
    return 0;
}