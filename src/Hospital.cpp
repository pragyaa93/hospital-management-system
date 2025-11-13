#include "Hospital.h"
#include <stdexcept>

Patient Hospital::addPatient(const std::string &name, int age, const std::string &gender, const std::string &contact) {
    Patient p(nextPatientId++, name, age, gender, contact);
    patients.push_back(p);
    return p;
}

Doctor Hospital::addDoctor(const std::string &name, const std::string &spec) {
    Doctor d(nextDoctorId++, name, spec);
    doctors.push_back(d);
    return d;
}

std::optional<Patient> Hospital::findPatientById(int id) const {
    for (const auto &p : patients) if (p.getId() == id) return p;
    return std::nullopt;
}

std::optional<Doctor> Hospital::findDoctorById(int id) const {
    for (const auto &d : doctors) if (d.getId() == id) return d;
    return std::nullopt;
}

Appointment Hospital::bookAppointment(int patientId, int doctorId, const std::string &date, const std::string &time) {
    auto p = findPatientById(patientId);
    if (!p) throw std::runtime_error("Patient not found");
    auto d = findDoctorById(doctorId);
    if (!d) throw std::runtime_error("Doctor not found");
    Appointment a(nextAppointmentId++, patientId, doctorId, date, time);
    appointments.push_back(a);
    return a;
}
