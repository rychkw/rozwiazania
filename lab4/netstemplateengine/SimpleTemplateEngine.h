#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>

using namespace std;

namespace nets {
    class View {
        string pattern;
    public:
        View(string str);
        string Render(const std::unordered_map <std::string, std::string> &model) const;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H