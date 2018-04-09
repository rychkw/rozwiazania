#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>

using namespace std;

namespace pool {
    class TextPool {
        set<string> pula;

    public:
        TextPool() = default;
        TextPool(initializer_list<string> pula);
        TextPool(TextPool &&nowe);
        TextPool &operator=(TextPool &&nowe);
        ~TextPool();
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
