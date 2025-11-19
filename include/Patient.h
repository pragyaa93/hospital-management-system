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
    Patient() : id(0), name(), age(0), gender(), contact() {}

    Patient(int id, const std::string &name, int age, const std::string &gender, const std::string &contact)
        : id(id), name(name), age(age), gender(gender), contact(contact) {}

    int getId() const noexcept { return id; }
    const std::string &getName() const noexcept { return name; }
    int getAge() const noexcept { return age; }
    const std::string &getGender() const noexcept { return gender; }
    const std::string &getContact() const noexcept { return contact; }

    void setName(const std::string &n) { name = n; }
    void setAge(int a) { age = a; }
    void setGender(const std::string &g) { gender = g; }
    void setContact(const std::string &c) { contact = c; }

    inline friend std::ostream &operator<<(std::ostream &os, const Patient &p) {
        os << "Patient[ID=" << p.id
           << ", Name=" << p.name
           << ", Age=" << p.age
           << ", Gender=" << p.gender
           << ", Contact=" << p.contact << "]";
        return os;
    }
};
