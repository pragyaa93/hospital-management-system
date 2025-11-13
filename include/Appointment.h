#pragma once
#include <string>
#include <iostream>

class Appointment {
private:
    int id;
    int patientId;
    int doctorId;
    std::string date;
    std::string time;

public:
    Appointment() : id(0), patientId(0), doctorId(0) {}

    Appointment(int id, int pid, int did, const std::string &date, const std::string &time)
        : id(id), patientId(pid), doctorId(did), date(date), time(time) {}

    int getId() const { return id; }
    int getPatientId() const { return patientId; }
    int getDoctorId() const { return doctorId; }
    std::string getDate() const { return date; }
    std::string getTime() const { return time; }

    friend std::ostream &operator<<(std::ostream &os, const Appointment &a) {
        os << "Appointment[ID=" << a.id
           << ", PatientID=" << a.patientId
           << ", DoctorID=" << a.doctorId
           << ", Date=" << a.date
           << ", Time=" << a.time << "]";
        return os;
    }
};
