#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H
#include<iostream>
#include<vector>

using std::string;
using std::ostream;
using std::vector;


namespace academia {
    class StudyYear  {
    public:
        int study_year;
        StudyYear();
        StudyYear(int x);
        void SetYear(int y);
        StudyYear & operator++();
        StudyYear & operator--();
        
        bool operator<(StudyYear another_study_year) const;
        bool operator>(StudyYear another_study_year) const;
        bool operator==(StudyYear another_study_year) const;
        operator int() const;
    };


    class Student {
    public:
        StudyYear year;
        string firstName;
        string lastName;
        string program;
        string id;

        Student();
        Student(string id_, string firstName_, string lastName_, string program_, int year_);
        
        string Id();
        string Program();
        string FirstName();
        string LastName();
        StudyYear Year();
        void ChangeLastName(string newLastName);
        bool operator==(Student another_student) const;
    };


    class StudentRepository{
    public:
        int studentCount;
        vector <Student> repository ;
        
        StudentRepository();
        StudentRepository(std::initializer_list<Student> list);
        
        int StudentCount();
        Student &operator[](string id);
        bool operator==(StudentRepository another_repository) const;

    };

    bool operator==(int age, StudyYear studentY);
    ostream &operator<<(ostream &s, const Student &v);
}
#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
