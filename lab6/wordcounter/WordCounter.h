#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <string>
#include <list>
#include <set>
#include <algorithm>

using std::list;
using std::string;
using std::pair;
using std::initializer_list;

namespace datastructures {
    class Word {
    public:
        friend class WordCounter;
        Word() {};
        Word(string str);
        bool operator<(const Word &word) const;
        bool operator>(const Word &word) const;
        bool operator==(const Word &word) const;
    private:
        string word;
    };

    class Counts {
    public:
        friend class WordCounter;
        Counts() {};
        Counts(int number);
        bool operator<(const Counts &count) const;
        bool operator>(const Counts &count) const;
        bool operator==(const Counts &count) const;
        Counts &operator++();
    private:
        int counts;
    };

    class WordCounter {
    public:
        WordCounter();
        WordCounter(initializer_list<Word> list1);
        int operator[](const string wanted) ;

        int DistinctWords();
        int TotalWords();
        std::set<Word> Words();
        WordCounter &operator<<(list<pair<Word, Counts>> lista);
    private:
        list<pair<Word, Counts>> lista;
        int distinct;
        int total;
    };
}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
