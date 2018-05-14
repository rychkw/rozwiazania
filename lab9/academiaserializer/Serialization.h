#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <functional>
#include <initializer_list>
#include <experimental/optional>


using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::reference_wrapper;
using std::ostream;
using std::stringstream;
using std::to_string;
using std::initializer_list;

namespace academia {
    class Serializable;
    class Serializer {
    public:
        explicit Serializer(ostream*out): out_(out){}
        virtual ~Serializer() = default;
        virtual void IntegerField(const string&field_name, int value)=0;
        virtual void DoubleField(const string&field_name, double value)=0;
        virtual void StringField(const string&field_name, const string&value)=0;
        virtual void BooleanField(const string&field_name, bool value)=0;
        virtual void SerializableField(const string&field_name, const Serializable &value)=0;
        virtual void ArrayField(const string&field_name, const vector<reference_wrapper<const Serializable>> &value)=0;
        virtual void Header(const string&object_name)=0;
        virtual void Footer(const string&object_name)=0;

    protected:
        ostream *out_;

    };

    class JsonSerializer: public Serializer {
    public:
        explicit JsonSerializer(ostream*out):Serializer(out){}
        void IntegerField(const string&field_name, int value) override;
        void DoubleField(const string&field_name, double value)override;
        void StringField(const string&field_name, const string&value)override;
        void BooleanField(const string&field_name, bool value)override;
        void SerializableField(const string&field_name, const Serializable &value)override;
        void ArrayField(const string&field_name, const vector<reference_wrapper<const Serializable>> &value)override;
        void Header(const string&object_name) override;
        void Footer(const string&object_name)override;
        void CheckIfFirst();

    protected:
        bool first = true;
    };


    class XmlSerializer: public Serializer {
    public:
        explicit XmlSerializer(ostream*out) : Serializer(out) {}
        void IntegerField(const string& field_name, int value) override;
        void DoubleField(const string& field_name, double value)override;
        void StringField(const string& field_name, const string&value)override;
        void BooleanField(const string& field_name, bool value)override;
        void SerializableField(const string& field_name, const Serializable &value)override;
        void ArrayField(const string& field_name, const vector<reference_wrapper<const Serializable>> &value)override;
        void Header(const string& object_name) override;
        void Footer(const string& object_name)override;
    };

    class Serializable{
    public:
        virtual ~Serializable()= default;
        virtual void Serialize(Serializer* serializer)const=0;
        virtual void Serialize(Serializer* serializer)=0;

    };

    class Room: public Serializable
    {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room(int id, string name, Type type);
        ~Room() override = default;
        void Serialize(Serializer* serializer)const override;
        void Serialize(Serializer* serializer) override;

    private:
        int id_;
        string name_;
        Type type_;

    };

    class Building: public Serializable {
        int id_;
        string name_;
        const vector<reference_wrapper<const academia::Serializable>> rooms_;
    public:
        Building(int id, string name, const vector<reference_wrapper<const academia::Serializable>> &rooms);
        void Serialize(Serializer* serializer)const override;
        void Serialize(Serializer* serializer) override;
        ~Building() override = default;
        int Id() const;
    };




    class BuildingRepository: public Serializable{
        vector<Building> vect;
    public:
        BuildingRepository()=default;
        explicit BuildingRepository(Building b);
        BuildingRepository(initializer_list<Building> initList);
        void Add(Building serializer);
        void StoreAll(Serializer*)const;
        std::experimental::optional<Building> operator[](int a)const;
    };

}

#endif //JIMP_EXERCISES_SERIALIZATION_H