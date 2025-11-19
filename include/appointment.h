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
    Appointment() : id(0), patientId(0), doctorId(0), date(), time() {}

    Appointment(int id, int pid, int did, const std::string &date, const std::string &time)
        : id(id), patientId(pid), doctorId(did), date(date), time(time) {}

    int getId() const noexcept { return id; }
    int getPatientId() const noexcept { return patientId; }
    int getDoctorId() const noexcept { return doctorId; }
    const std::string &getDate() const noexcept { return date; }
    const std::string &getTime() const noexcept { return time; }

    void setDate(const std::string &d) { date = d; }
    void setTime(const std::string &t) { time = t; }

    inline friend std::ostream &operator<<(std::ostream &os, const Appointment &a) {
        os << "Appointment[ID=" << a.id
           << ", PatientID=" << a.patientId
           << ", DoctorID=" << a.doctorId
           << ", Date=" << a.date
           << ", Time=" << a.time << "]";
        return os;
    }
};
