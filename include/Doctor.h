#pragma once
#include <string>
#include <iostream>

class Doctor {
private:
    int id;
    std::string name;
    std::string specialty;
public:
    Doctor() : id(0) {}
    Doctor(int id, const std::string &name, const std::string &spec)
        : id(id), name(name), specialty(spec) {}
    int getId() const { return id; }
    std::string getName() const { return name; }

    friend std::ostream &operator<<(std::ostream &os, const Doctor &d) {
        os << "Doctor[ID=" << d.id << ", Name=" << d.name << ", Spec=" << d.specialty << "]";
        return os;
    }
};
