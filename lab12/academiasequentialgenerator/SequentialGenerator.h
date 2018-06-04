#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H


#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


template<class T, class SimpleType>
class SequentialIdGenerator {
    bool first;
    SimpleType counter;
public:
    SequentialIdGenerator() {
        first = true;
        counter = 0;
    }

    SequentialIdGenerator(SimpleType value) {
        first = true;
        counter = value;
    }

    T NextValue() {
        if (!first)
            ++counter;
        first = false;
        return T(counter);
    }

};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
