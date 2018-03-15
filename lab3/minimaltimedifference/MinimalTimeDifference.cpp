//
// Created by kwiasylw on 13.03.18.
//

#include "MinimalTimeDifference.h"
using namespace std;

namespace minimaltimedifference {
    unsigned int ToMinutes(std::string time_HH_MM) {
        regex pattern{R"((\d{1,2}):(\d{2}))"};
        smatch matches;
        if (regex_match(time_HH_MM, matches, pattern)) {
            string hours = matches[1].str();
            string minutes = matches[2].str();

            int number_hours = std::stoi(hours);
            int number_minutes = std::stoi(minutes);
            int total_minutes = number_hours * 60 + number_minutes;
            return total_minutes;
        }
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {
        vector<int> minutes;
        for (string time : times) {
            minutes.push_back(ToMinutes(time));
        }
        int minTimeDifference = 24 * 60 + 1;
        for (int i = 0; i < minutes.size() - 1; i++) {
            for (int j = i + 1; j < minutes.size(); j++) {
                int dif = abs(minutes[j] - minutes[i]);
                if (dif > 12 * 60) {
                    dif = 24 * 60 - dif;
                }
                if (dif < minTimeDifference) {
                    minTimeDifference = dif;
                }
            }
        }
        return minTimeDifference;
    }
}


/*  II sposob z bledami testow
    unsigned int MinimalTimeDifference(std::vector<std::string> times) {
        vector<unsigned int> minutes;
        for (string time : times) {
            minutes.push_back(ToMinutes(time));
        }
        sort(minutes.begin(), minutes.end());
        int minimum = 60 * 24 + 1;
        for (int i = 0; i < minutes.size() - 1; i++) {
            if (minutes[i + 1] - minutes[i] < minimum) {
                minimum = minutes[i + 1] - minutes[i];
            }
        }
        if ((minutes[0] + (24 * 60)) - minutes[minutes.size()] < minimum) {
            minimum = (minutes[0] + (24 * 60)) - minutes[minutes.size()];
        }
        return minimum;
    }
}*/
