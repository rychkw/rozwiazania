
#include "StudentRepository.h"

namespace academia {
    StudyYear::StudyYear() {
        study_year = 1;
    }
    
    StudyYear::StudyYear(int x) {
        study_year = x;
    }

    void StudyYear::SetYear(int y) {
        study_year = y;
    }

    StudyYear & StudyYear::operator++() {
        study_year += 1;
        return *this;
    }

    StudyYear & StudyYear::operator--() {
        study_year -= 1;
        return *this;
    }

    bool StudyYear::operator<(StudyYear another_study_year) const {
        return study_year < another_study_year.study_year;
    }

    bool StudyYear::operator>(StudyYear another_study_year) const {
        return study_year > another_study_year.study_year;
    }
    
    bool StudyYear::operator==(StudyYear another_study_year) const {
        return study_year == another_study_year.study_year;
    }
    
    StudyYear::operator int() const {
        return study_year;
    }
    
    
    
    
    Student::Student() {
        id = "";
    }
    
    Student::Student(string id_, string name_, string lastName_, string program_, int year_) {
        id= id_;
        firstName = name_;
        lastName = lastName_;
        program = program_;
        year.SetYear(year_);
    }
    
    string Student::Id() {
        return id;
    }

    string Student::Program() {
        return program;
    }

    string Student::FirstName() {
        return firstName;
    }

    string Student::LastName() {
        return lastName;
    }

    StudyYear Student::Year() {
        return year.study_year;
    }

    void Student::ChangeLastName(string newLastName) {
        lastName = newLastName;
    }

    bool Student::operator==(Student another_student) const {
        return id == another_student.id;
    }
    
    
    
    
    StudentRepository::StudentRepository() {
        studentCount = 0;
    }

    StudentRepository::StudentRepository(std::initializer_list<Student> list) {
        studentCount = 0;
        for(auto iter : list) {
            repository.emplace_back(iter);
            studentCount ++;
        }
    }
    
    int StudentRepository::StudentCount() {
        return studentCount;
    }
    
    Student &StudentRepository::operator[](string id) {
        for (auto &iter : repository) {
            if (id == iter.id) {
                return  iter;
            }
        }
    }
    
    bool StudentRepository::operator==(StudentRepository another_repository) const{
        for(auto iter : repository) {
            if(another_repository[iter.id] == iter){
                return true;
            }
        }
        return false;
    }
    
    
    
    
    bool operator==(int age, StudyYear studentY){
        if(age == studentY.study_year){
            return true;
        }
        return false;
    }
    
    ostream &operator<<(ostream &s, const Student &v) {
        return s << "Student " << v.lastName << std::endl << "id: " << v.id << std::endl << "program: " << v.program;
    }
}
