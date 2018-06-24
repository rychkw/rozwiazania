#include "Algo.h"

namespace algo {
    set<string> Keys(const map<string, int> &m) {
        set<string> output;
        transform(m.begin(), m.end(), std::inserter(output, output.begin()),
                  [](pair<string, int> pair) { return pair.first; });
        return output;
    }

    vector<int> Values(const map<string, int> &m) {
        vector<int> output;
        transform(m.begin(), m.end(), back_inserter(output),
                  [](pair<string, int> pair) { return pair.second; });
        return output;
    }

    vector<int> DivisableBy(const vector<int> &m, int divisor) {
        vector<int> output;
        copy_if(m.begin(), m.end(), back_inserter(output),
                [divisor](int number) { return number % divisor == 0; });
        return output;
    }

    void SortInPlace(vector<int> *v) {
        sort(v->begin(), v->end());
    }

    vector<int> Sort(const vector<int> &v) {
        vector<int> l = v;
        sort(l.begin(), l.end());
        return l;
    }

    void SortByFirstInPlace(vector<pair<int, int>> *v) {
        sort(v->begin(), v->end(), [](pair<int, int> x, pair<int, int> y) { return x.first < y.first; });

    }

    void SortBySecondInPlace(vector<pair<int, int>> *v) {
        sort(v->begin(), v->end(),
             [](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });

    }

    void SortByThirdInPlace(vector<std::tuple<int, int, int>> *v) {
        sort(v->begin(), v->end(), [](std::tuple<int, int, int> x, std::tuple<int, int, int> y) {
            return std::get<2>(x) < std::get<2>(y);
        });
    }

    vector<string> MapToString(const vector<double> &v) {
        vector<string> result;
        transform(v.begin(), v.end(), std::inserter(result, result.begin()),
                  [](double p) { return std::to_string(p); });
        return result;
    }

    string Join(const string &joiner, const vector<double> &v) {
        return std::__cxx11::string();
    }

    int Sum(const vector<int> &v) {
        int sum = std::accumulate(v.begin(), v.end(), 0);
        return sum;
    }


    int Product(const vector<int> &v) {
        int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
        return product;
    }


    bool Contains(const vector<int> &v, int element) {
        return v.end() != std::find(v.begin(), v.end(), element);
    }

    bool ContainsKey(const map<string, int> &v, const string &key) {
        return (v.find(key) != v.end());
    }

    bool ContainsValue(const map<string, int> &v, int value) {
        return v.end() != std::find_if(v.begin(), v.end(),
                                       [value](pair<string, int> pair) { return pair.second == value; });
    }

    vector<string> RemoveDuplicates(const vector<string> &v) {
        return vector<string>();
    }

    void RemoveDuplicatesInPlace(vector<string> *v) {
        sort(v->begin(), v->end());
        v->erase(unique(v->begin(), v->end()), v->end());
    }

    void InitializeWith(int initial_value, vector<int> *v) {
        std::fill(v->begin(), v->end(), initial_value);
    }

    vector<int> InitializedVectorOfLength(int length, int initial_value) {
        vector<int> v;
        v.resize((unsigned long) length);
        std::fill_n(v.begin(), length, initial_value);
        return v;
    }

    void CopyInto(const vector<int> &v, int n_elements, vector<int> *out) {
        out->resize((unsigned long) n_elements);
        std::copy_n(v.begin(), n_elements, out->begin());
    }

    long HowManyShortStrings(const vector<string> &v, int inclusive_short_length) {
        return std::count_if(v.begin(), v.end(),
                             [&](const string test) { return (test.length() <= inclusive_short_length); });
    }
}
