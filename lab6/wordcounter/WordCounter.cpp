#include "WordCounter.h"

using namespace datastructures;

Word::Word(std::string str) {
    word = str;
}

bool Word::operator <(const Word &word1) const{
    return (word < word1.word);
}

bool Word::operator >(const Word &word1) const{
    return (word > word1.word);
}

bool Word::operator ==(const Word &word1) const{
    return (word == word1.word);
}

Counts::Counts(int number) {
    counts = number;
}

bool Counts::operator<(const Counts &count1) const{
    return (counts < count1.counts);
}

bool Counts::operator>(const Counts &count1) const{
    return (counts > count1.counts);
}

bool Counts::operator==(const Counts &count1) const{
    return (counts == count1.counts);
}

Counts &Counts::operator++() {
    counts++;
}

WordCounter &WordCounter::operator<<(list<pair<Word, Counts>> list1) {
    std::cout<<"liczba slow: "<<total<<"  liczba unikalnych slow: "<<distinct<<"\n";
    list1.sort();
}

WordCounter::WordCounter() {
    distinct = 0;
    total = 0;
}

WordCounter::WordCounter(std::initializer_list<Word> list1) {
    distinct = 0;
    total = 0;
    bool is_new;
    for (auto currentw : list1){
        total++;
        is_new = true;
        for(std::pair<Word, Counts> &it : lista) {
            if (it.first.word == currentw.word) {
                ++it.second;
                is_new = false;
                break;
            }
        }
        if(is_new){
            Counts new_entry_nr(1);
            lista.emplace_back(std::make_pair(currentw,new_entry_nr));
            distinct++;
        }
    }
}

int WordCounter::operator[](const string wanted) {
    for(auto it : lista) {
        if(it.first.word == wanted)
            return it.second.counts;
    }
    return 0;
}

int WordCounter::DistinctWords() {
    return distinct;
}

int WordCounter::TotalWords() {
    return total;
}

std::set<Word> WordCounter::Words(){
    std::set<Word> words_set;
    for(auto &it : lista){
        words_set.emplace(it.first);
    }
    return words_set;
}
