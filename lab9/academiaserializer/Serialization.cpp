#include "Serialization.h"

using namespace academia;


Room::Room (int id, string name, Room::Type type) : id_{id},name_{name},type_{type} {}


void Room::Serialize(Serializer *serializer) const {
    serializer->Header("room");
    serializer->IntegerField("id", this->id_);
    serializer->StringField("name", this->name_);
    if (this->type_ == Type::CLASSROOM) {
        serializer->StringField("type", "CLASSROOM");
    }
    else if (this->type_ == Type::COMPUTER_LAB) {
        serializer->StringField("type", "COMPUTER_LAB");
    }
    else {
        serializer->StringField("type", "LECTURE_HALL");
    }
    serializer->Footer("room");
}

void Room::Serialize(Serializer *serializer) {
    serializer->Header("room");
    serializer->IntegerField("id", this->id_);
    serializer->StringField("name", this->name_);
    if (this->type_ == Type::CLASSROOM) {
        serializer->StringField("type", "CLASSROOM");
    }
    else if (this->type_ == Type::COMPUTER_LAB) {
        serializer->StringField("type", "COMPUTER_LAB");
    }
    else {
        serializer->StringField("type", "LECTURE_HALL");
    }
    serializer->Footer("room");
}





Building::Building(int id, string name,
                   const vector<reference_wrapper<const academia::Serializable>> &rooms) : id_{id}, name_{name}, rooms_{rooms} {}

void Building::Serialize(Serializer *serializer) const {
    serializer->Header("building");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->ArrayField("rooms", rooms_);
    serializer->Footer("building");
}

void Building::Serialize(Serializer *serializer) {
    serializer->Header("building");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->ArrayField("rooms", rooms_);
    serializer->Footer("building");
}

int Building::Id() const {
    return id_;
}






void JsonSerializer::IntegerField(const string &field_name, int value) {
    CheckIfFirst();
    *out_ << "\"" << field_name << "\": " << value;

}

void JsonSerializer::DoubleField(const string &field_name, double value) {
    CheckIfFirst();
    *out_ << "\"" << field_name << "\": " << value;

}

void JsonSerializer::StringField(const string &field_name, const string &value) {
    CheckIfFirst();
    *out_ << "\"" << field_name << "\": \"" << value << "\"";

}

void JsonSerializer::BooleanField(const string &field_name, bool value) {
    CheckIfFirst();
    *out_ << "\"" << field_name << "\": \"";
}

void JsonSerializer::SerializableField(const string &field_name, const Serializable &value) {
    CheckIfFirst();
    value.Serialize(this);

}

void JsonSerializer::ArrayField(const string &field_name,
                                const vector<reference_wrapper<const Serializable>> &value) {
    CheckIfFirst();
    *(out_) << "\"" << field_name << "\": [";

    bool temp = false;
    for (const Serializable &p: value) {
        if (temp)
            *out_ << ", ";
        first = true;
        p.Serialize(this);
        temp = true;
    }
    *out_ << "]";
}

void JsonSerializer::Header(const string &object_name) {
    *out_ << "{";

}

void JsonSerializer::Footer(const string &object_name) {
    *out_ << "}";
}

void JsonSerializer::CheckIfFirst() {
    if (first) {
        first = false;
    }
    else {
        *out_ << ", ";
    }
}






void XmlSerializer::IntegerField(const string &field_name, int value) {
    *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void XmlSerializer::DoubleField(const string &field_name, double value) {
    *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void XmlSerializer::StringField(const string &field_name, const string &value) {
    *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void XmlSerializer::BooleanField(const string &field_name, bool value) {
    *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}


void XmlSerializer::SerializableField(const string &field_name, const Serializable &value) {
    value.Serialize(this);
}

void XmlSerializer::ArrayField(const string &field_name, const vector<reference_wrapper<const Serializable>> &value) {
    *out_ << "<" << field_name << ">";
    for (const Serializable &v: value) {
        v.Serialize(this);
    }
    *out_ << "<\\" << field_name << ">";
}

void XmlSerializer::Header(const string &object_name) {
    *out_ << "<" << object_name << ">";

}

void XmlSerializer::Footer(const string &object_name) {
    *out_ << "<\\" << object_name << ">";
}






void BuildingRepository::Add(Building temp) {
    vect.emplace_back(temp);
}

BuildingRepository::BuildingRepository(Building b) {
    Add(b);
}

BuildingRepository::BuildingRepository(initializer_list<Building> initList) {
    for (auto &i:initList){
        vect.emplace_back(i);
    }
}


void BuildingRepository::StoreAll(Serializer *serializer) const {
    serializer->Header("building_repository");
    vector<reference_wrapper<const Serializable>> v;
    for (auto i: vect) {
        v.emplace_back(i);
    }
    serializer->ArrayField("buildings", v);
    serializer->Footer("building_repository");
}

std::experimental::optional<Building> BuildingRepository::operator[](int a) const {
    for (auto v: vect) {
        if (v.Id() == a) {
            return std::experimental::make_optional(v);
        }
    }
}