#pragma once
#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"
#include <vector>
#include <optional>

class Hospital {
private:
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
    std::vector<Appointment> appointments;
    int nextPatientId = 1;
    int nextDoctorId = 1;
    int nextAppointmentId = 1;
public:
    Patient addPatient(const std::string &name, int age, const std::string &gender, const std::string &contact);
    Doctor addDoctor(const std::string &name, const std::string &spec);
    std::optional<Patient> findPatientById(int id) const;
    std::optional<Doctor> findDoctorById(int id) const;
    Appointment bookAppointment(int patientId, int doctorId, const std::string &date, const std::string &time);
};
