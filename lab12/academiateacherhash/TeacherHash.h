#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <iostream>
#include <string>

using std::string;


namespace academia {
    class TeacherId {
        int id_;
    public:
        TeacherId() : id_(0) {}

        TeacherId(int id) : id_(id) {}

        ~TeacherId() {}

        operator int() const { return id_; }

    };

    class Teacher {
        TeacherId id_;
        string name_;
        string dep_;
    public:
        Teacher() : id_(0), name_(""), dep_("") {}

        Teacher(const TeacherId &id, string name, string dep) : id_(id), name_(name), dep_(dep) {}

        ~Teacher() {}

        TeacherId Id() const { return id_; }

        string Name() const { return name_; }

        string Department() const { return dep_; }

        bool operator==(const Teacher &other) const {
            return (id_ == other.id_ && name_ == other.name_ && dep_ == other.dep_);
        }

        bool operator!=(const Teacher &teach2) const {
            return (id_ != teach2.id_ || name_ != teach2.name_ || dep_ != teach2.dep_);
        }
    };


    struct TeacherHash {
    public:
        size_t operator()(const Teacher &teacher) const {
            auto h1 = std::hash<int>()(teacher.Id());
            auto h2 = std::hash<string>()(teacher.Name());
            auto h3 = std::hash<string>()(teacher.Department());
            return h1*h2/h3;
        }
    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H

