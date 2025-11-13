#pragma once
#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"
#include "Billing.h"
#include <vector>
#include <optional>
#include <string>

class Hospital {
private:
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
    std::vector<Appointment> appointments;
    std::vector<Billing> bills;

    int nextPatientId = 1;
    int nextDoctorId = 1;
    int nextAppointmentId = 1;
    int nextBillId = 1;

public:

    // Patients
    Patient addPatient(const std::string &name, int age, const std::string &gender, const std::string &contact);
    std::optional<Patient> findPatientById(int id) const;

    // Doctors
    Doctor addDoctor(const std::string &name, const std::string &spec, const std::string &contact);
    std::optional<Doctor> findDoctorById(int id) const;

    // Appointments
    Appointment bookAppointment(int patientId, int doctorId, const std::string &date, const std::string &time);
    std::vector<Appointment> getAllAppointments() const;

    // Billing
    Billing generateBill(int appointmentId);
    std::vector<Billing> getAllBills() const;

    // CSV
    void loadPatients(const std::string &file);
    void loadDoctors(const std::string &file);
    void loadAppointments(const std::string &file);
    void loadBilling(const std::string &file);

    void savePatients(const std::string &file);
    void saveDoctors(const std::string &file);
    void saveAppointments(const std::string &file);
    void saveBilling(const std::string &file);
};
