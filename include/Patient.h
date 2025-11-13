#pragma once
#include <string>
#include <iostream>

class Patient {
private:
    int id;
    std::string name;
    int age;
    std::string gender;
    std::string contact;

public:
    Patient() : id(0), age(0) {}

    Patient(int id, const std::string &name, int age, const std::string &gender, const std::string &contact)
        : id(id), name(name), age(age), gender(gender), contact(contact) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getGender() const { return gender; }
    std::string getContact() const { return contact; }

    friend std::ostream &operator<<(std::ostream &os, const Patient &p) {
        os << "Patient[ID=" << p.id
           << ", Name=" << p.name
           << ", Age=" << p.age
           << ", Gender=" << p.gender
           << ", Contact=" << p.contact << "]";
        return os;
    }
};
