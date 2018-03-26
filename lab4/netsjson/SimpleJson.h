#ifndef JIMP_EXERCISES_JSONVALUE_H
#define JIMP_EXERCISES_JSONVALUE_H
#include <experimental/optional>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

namespace nets
{
    class JsonValue {
    private:
        int rodzaj;
        int calkowita;
        double rzeczywista;
        string tekst;
        bool logiczna;
        vector <JsonValue> wektor;
        map <string,JsonValue> mapa;
    public:
        JsonValue(int calkowita);
        JsonValue(double rzeczywista);
        JsonValue(const string &tekst);
        JsonValue(bool logiczna);
        JsonValue(const vector<JsonValue> &wektor);
        JsonValue(const map<string, JsonValue> &mapa);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;
    };
}

using namespace nets;

#endif //JIMP_EXERCISES_JSONVALUE_H
