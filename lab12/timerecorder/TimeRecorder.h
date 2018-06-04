#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <utility>
#include <iostream>
#include <string>
#include <unordered_map>
#include <ctime>

namespace profiling {

    template<class T>
    auto TimeRecorder(T object) {

        auto before = std::chrono::system_clock::now();
        auto value = object();
        auto after = std::chrono::system_clock::now();

        std::chrono::duration<double> span = after-before;
        auto x=(span.count()+0.001)*1000;

        return std::make_pair(value, x);
    }
}
#endif //JIMP_EXERCISES_TIMERECORDER_H
