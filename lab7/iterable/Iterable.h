#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>


using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::pair;
using std::make_pair;
using std::unique_ptr;
using std::make_unique;
using std::move;

namespace utility {

    class IterableIterator{
    public :
        virtual pair<int, string> Dereference() const = 0;
        virtual IterableIterator &Next() = 0;
        virtual bool NotEquals(const unique_ptr<IterableIterator> &other) const = 0;
        virtual ~IterableIterator() = default;
    };



    class ZipperIterator : public IterableIterator {
    public:
        vector<int>::const_iterator left_begin_;
        vector<int>::const_iterator left_end_;
        vector<string>::const_iterator right_begin_;
        vector<string>::const_iterator right_end_;

        explicit ZipperIterator(vector<int>::const_iterator left_begin,
                                vector<string>::const_iterator right_begin,
                                vector<int>::const_iterator left_end,
                                vector<string>::const_iterator right_end);

        explicit ZipperIterator(vector<int>::const_iterator left, vector<string>::const_iterator right);

        pair<int, string> Dereference() const override;
        IterableIterator &Next() override;
        bool NotEquals(const unique_ptr<IterableIterator> &other) const override;
        //~ZipperIterator() override = default;
    };



    class IterableIteratorWrapper {
        unique_ptr<IterableIterator> iterator_;
    public:
        explicit IterableIteratorWrapper(unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other);
        pair<int, string> operator*();
        IterableIteratorWrapper &operator++();
    };



    class Iterable{
    public:
        virtual unique_ptr<IterableIterator> ConstBegin() const = 0;
        virtual unique_ptr<IterableIterator> ConstEnd() const = 0;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;
        ~Iterable() = default;
    };



    class Zipper : public Iterable{
        vector<int> v1;
        vector<string> v2;
    public:
        Zipper(vector <int> vi, vector <string> v2);
        unique_ptr<IterableIterator> ConstBegin() const override;
        unique_ptr<IterableIterator> ConstEnd() const override;
    };



    class EnumerateIterator : public IterableIterator{
        unsigned int index;
        std::vector<std::string>::const_iterator begin;
        std::vector<std::string>::const_iterator end;
    public:
        explicit EnumerateIterator(vector<string>::const_iterator vbeg, vector<string>::const_iterator vend);
        pair<int, string> Dereference() const override;
        IterableIterator& Next() override ;
        bool NotEquals(const unique_ptr<IterableIterator> &other) const override ;
    };



    class Enumerate : public Iterable {
        vector<string> enu;
    public:
        explicit Enumerate(vector <string> vs);
        unique_ptr<IterableIterator> ConstBegin() const override;
        unique_ptr<IterableIterator> ConstEnd() const override;
    };



    class ProductIterator : public IterableIterator {
    public:
        vector<int>::const_iterator left_begin_;
        vector<int>::const_iterator left_end_;
        vector<string>::const_iterator right_begin_;
        vector<string>::const_iterator right_end_;
        vector<string>::const_iterator right_start_;

        explicit ProductIterator(vector<int>::const_iterator left_begin,
                                 vector<string>::const_iterator right_begin,
                                 vector<int>::const_iterator left_end,
                                 vector<string>::const_iterator right_end,
                                 vector<string>::const_iterator right_start);
        pair<int, string> Dereference() const override;
        IterableIterator& Next() override ;
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override;
        ~ProductIterator() override = default;
    };



    class Product : public Iterable{
        vector<int> v1;
        vector<string> v2;
    public:
        Product(vector<int>, vector<string>);
        unique_ptr<IterableIterator> ConstBegin() const override;
        unique_ptr<IterableIterator> ConstEnd() const override;
    };
}

#endif //JIMP_EXERCISES_ITERABLEITERATOR_H