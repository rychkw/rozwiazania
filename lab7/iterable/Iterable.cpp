#include <iostream>
#include "Iterable.h"

using namespace utility;


ZipperIterator::ZipperIterator(vector<int>::const_iterator left_begin,
                               vector<string>::const_iterator right_begin,
                               vector<int>::const_iterator left_end,
                               vector<string>::const_iterator right_end) {
    left_begin_ = left_begin;
    right_begin_ = right_begin;
    left_end_ = left_end;
    right_end_ = right_end;
}


ZipperIterator::ZipperIterator(vector<int>::const_iterator left, vector<string>::const_iterator right) {
    left_begin_ = left;
    right_begin_ = right;

}

pair<int, string> ZipperIterator::Dereference() const {
    if (left_begin_ == left_end_ && right_begin_ == right_end_) {
        return (pair<int, string>{0, ""});
    }
    else {
        return (pair<int, string>{*left_begin_, *right_begin_});
    }
};


IterableIterator &ZipperIterator::Next() {
    if (left_begin_ + 1 == left_end_ && right_begin_ + 1 == right_end_) {
        left_begin_ = left_end_;
        right_begin_ = right_end_;
    }
    else {
        if (left_begin_ + 1 != left_end_) {
            ++left_begin_;
        }
        if (right_begin_ + 1 != right_end_) {
            ++right_begin_;
        }
    }
    return *this;
}

bool ZipperIterator::NotEquals(const unique_ptr<IterableIterator> &other) const {
    return ((Dereference().first != (*other).Dereference().first) ? true : false);
}



IterableIteratorWrapper::IterableIteratorWrapper(unique_ptr<IterableIterator> other) {
    iterator_ = move(other);
}

bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) {
    return iterator_->NotEquals(other.iterator_);
}

pair<int, string> IterableIteratorWrapper::operator*() {
    return iterator_->Dereference();
}

IterableIteratorWrapper &IterableIteratorWrapper::operator++() {
    iterator_->Next();
    return *this;
}



IterableIteratorWrapper Iterable::cbegin() const {
    return IterableIteratorWrapper(ConstBegin());
}

IterableIteratorWrapper Iterable::cend() const {
    return IterableIteratorWrapper(ConstEnd());
}

IterableIteratorWrapper Iterable::begin() const {
    return cbegin();
}

IterableIteratorWrapper Iterable::end() const {
    return cend();
}



Zipper::Zipper(vector<int> vi, vector<string> vs) {
    v1 = move(vi);
    v2 = move(vs);
}

unique_ptr<IterableIterator> Zipper::ConstBegin() const {
    return make_unique<ZipperIterator>(v1.begin(), v2.begin(), v1.end(), v2.end());
}

unique_ptr<IterableIterator> Zipper::ConstEnd() const {
    return make_unique<ZipperIterator>(v1.end(), v2.end(), v1.end(), v2.end());
}



EnumerateIterator::EnumerateIterator(vector<string>::const_iterator vbeg, vector<string>::const_iterator vend) {
    begin = vbeg;
    end = vend;
    index = 1;
}

pair<int, string> EnumerateIterator::Dereference() const {
    if (begin != end) {
        return pair<int, string>(index, *begin);
    }
    else {
        return pair<int, string>(0, "");
    }
}

IterableIterator &EnumerateIterator::Next() {
    if (begin != end) {
        ++begin;
        ++index;
    }
    return *this;
}

bool EnumerateIterator::NotEquals(const unique_ptr<IterableIterator> &other) const {
    return Dereference() != other->Dereference();
}



Enumerate::Enumerate(vector<string> vs) {
    enu = move(vs);
}

unique_ptr<IterableIterator> Enumerate::ConstBegin() const {
    return make_unique<EnumerateIterator>(enu.begin(), enu.end());
}

unique_ptr<IterableIterator> Enumerate::ConstEnd() const {
    return make_unique<EnumerateIterator>(enu.end(), enu.end());
}



ProductIterator::ProductIterator(vector<int>::const_iterator left_begin,
                                 vector<string>::const_iterator right_begin,
                                 vector<int>::const_iterator left_end,
                                 vector<string>::const_iterator right_end,
                                 vector<string>::const_iterator right_start) {
    left_begin_ = left_begin;
    right_begin_ = right_begin;
    left_end_ = left_end;
    right_end_ = right_end;
    right_start_ = right_start;
}

pair<int, string> ProductIterator::Dereference() const {
    if (right_begin_ == right_end_ || left_begin_ == left_end_) {
        pair<int, string> xyz;

        if (left_begin_ == left_end_) {
            xyz.second = "";
        }
        else {
            xyz.second = *right_begin_;
        }

        if (right_begin_ == right_end_) {
            xyz.first = 0;
        }
        else {
            xyz.first = *left_begin_;
        }

        return xyz;
    }
    return pair<int, string>{*left_begin_, *right_begin_};
}


IterableIterator &ProductIterator::Next() {
    if (left_begin_ == left_end_) {
        return *this;
    }

    ++right_begin_;

    if (right_begin_ == right_end_) {
        ++left_begin_;

        if (left_begin_ != left_end_) {
            right_begin_ = right_start_;
        }
    }
    return *this;
}

bool ProductIterator::NotEquals(const unique_ptr<IterableIterator> &other) const {
    return ((Dereference().first != (*other).Dereference().first) ? true : false);
}



Product::Product(vector<int> vi, vector<string> vs) {
    v1 = move(vi);
    v2 = move(vs);
}

unique_ptr<IterableIterator> Product::ConstBegin() const {
    return make_unique<ProductIterator>(v1.begin(), v2.begin(), v1.end(), v2.end(), v2.begin());
}

unique_ptr<IterableIterator> Product::ConstEnd() const {
    return make_unique<ProductIterator>(v1.end(), v2.end(), v1.end(), v2.end(), v2.begin());
}