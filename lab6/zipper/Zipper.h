#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

#include "iostream"
#include "vector"
#include "string"

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::pair;
using std::make_pair;


namespace datastructures{
    class Zipper {
    public:
        static vector<pair<string, int>> zip(vector <string> v1, vector <int> v2);
    };
}

#endif //JIMP_EXERCISES_ZIPPER_H
