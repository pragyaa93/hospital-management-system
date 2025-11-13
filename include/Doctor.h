#pragma once
#include <string>
#include <iostream>

class Doctor {
private:
    int id;
    std::string name;
    std::string specialty;
    std::string contact;

public:
    Doctor() : id(0) {}

    Doctor(int id, const std::string &name, const std::string &specialty, const std::string &contact)
        : id(id), name(name), specialty(specialty), contact(contact) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getSpecialty() const { return specialty; }
    std::string getContact() const { return contact; }

    friend std::ostream &operator<<(std::ostream &os, const Doctor &d) {
        os << "Doctor[ID=" << d.id
           << ", Name=" << d.name
           << ", Specialty=" << d.specialty
           << ", Contact=" << d.contact << "]";
        return os;
    }
};
