#include "Hospital.h"
#include "CSVUtils.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

// --------------------------------------------------
//  INTERNAL BILLING FUNCTION (based on doctor specialty)
// --------------------------------------------------

double getConsultationFee(const std::string &specialty) {
    if (specialty == "Cardiology") return 800;
    if (specialty == "Neurology") return 900;
    if (specialty == "Orthopedics") return 700;
    if (specialty == "Dermatology") return 500;
    if (specialty == "Gynecology") return 600;
    if (specialty == "General Medicine") return 400;
    if (specialty == "Oncology") return 850;
    if (specialty == "Pediatrics") return 500;
    if (specialty == "ENT") return 450;
    if (specialty == "Ophthalmology") return 550;
    if (specialty == "Endocrinology") return 700;
    if (specialty == "Nephrology") return 750;
    if (specialty == "Gastroenterology") return 720;
    if (specialty == "Pulmonology") return 650;
    if (specialty == "Urology") return 680;
    if (specialty == "Rheumatology") return 670;
    return 500; // default
}

// --------------------------------------------------
//  PATIENTS
// --------------------------------------------------

Patient Hospital::addPatient(const std::string &name, int age, const std::string &gender, const std::string &contact) {
    Patient p(nextPatientId++, name, age, gender, contact);
    patients.push_back(p);
    return p;
}

std::optional<Patient> Hospital::findPatientById(int id) const {
    for (const auto &p : patients)
        if (p.getId() == id) return p;
    return std::nullopt;
}

// --------------------------------------------------
//  DOCTORS
// --------------------------------------------------

Doctor Hospital::addDoctor(const std::string &name, const std::string &spec, const std::string &contact) {
    Doctor d(nextDoctorId++, name, spec, contact);
    doctors.push_back(d);
    return d;
}

std::optional<Doctor> Hospital::findDoctorById(int id) const {
    for (const auto &d : doctors)
        if (d.getId() == id) return d;
    return std::nullopt;
}

// --------------------------------------------------
//  APPOINTMENTS
// --------------------------------------------------

Appointment Hospital::bookAppointment(int patientId, int doctorId, const std::string &date, const std::string &time) {
    if (!findPatientById(patientId)) throw std::runtime_error("Patient not found");
    if (!findDoctorById(doctorId))   throw std::runtime_error("Doctor not found");

    Appointment a(nextAppointmentId++, patientId, doctorId, date, time);
    appointments.push_back(a);
    return a;
}

std::vector<Appointment> Hospital::getAllAppointments() const {
    return appointments;
}

// --------------------------------------------------
//  BILLING
// --------------------------------------------------

Billing Hospital::generateBill(int appointmentId) {
    // find appointment
    Appointment *ap = nullptr;
    for (auto &a : appointments) {
        if (a.getId() == appointmentId) {
            ap = &a;
            break;
        }
    }
    if (!ap) throw std::runtime_error("Appointment not found");

    // find doctor
    auto doc = findDoctorById(ap->getDoctorId());
    if (!doc) throw std::runtime_error("Doctor not found");

    double fee = getConsultationFee(doc->getSpecialty());

    Billing b(
        nextBillId++,
        ap->getId(),
        doc->getId(),
        fee,
        "Consultation Fee",
        ap->getDate()
    );

    bills.push_back(b);
    return b;
}

std::vector<Billing> Hospital::getAllBills() const {
    return bills;
}

// --------------------------------------------------
// LOAD (CSV)
// --------------------------------------------------

void Hospital::loadPatients(const std::string &file) {
    auto rows = CSV::readCSV(file);
    for (auto &r : rows) {
        if (r.size() < 5) continue;
        int id = stoi(r[0]);
        patients.emplace_back(id, r[1], stoi(r[2]), r[3], r[4]);
        if (id >= nextPatientId) nextPatientId = id + 1;
    }
    std::cout << "Loaded " << patients.size() << " patients.\n";
}

void Hospital::loadDoctors(const std::string &file) {
    auto rows = CSV::readCSV(file);
    for (auto &r : rows) {
        if (r.size() < 4) continue;
        int id = stoi(r[0]);
        doctors.emplace_back(id, r[1], r[2], r[3]);
        if (id >= nextDoctorId) nextDoctorId = id + 1;
    }
    std::cout << "Loaded " << doctors.size() << " doctors.\n";
}

void Hospital::loadAppointments(const std::string &file) {
    auto rows = CSV::readCSV(file);
    for (auto &r : rows) {
        if (r.size() < 5) continue;
        int id = stoi(r[0]);
        appointments.emplace_back(id, stoi(r[1]), stoi(r[2]), r[3], r[4]);
        if (id >= nextAppointmentId) nextAppointmentId = id + 1;
    }
    std::cout << "Loaded " << appointments.size() << " appointments.\n";
}

void Hospital::loadBilling(const std::string &file) {
    auto rows = CSV::readCSV(file);
    for (auto &r : rows) {
        if (r.size() < 6) continue;
        int id = stoi(r[0]);
        bills.emplace_back(id, stoi(r[1]), stoi(r[2]), stod(r[3]), r[4], r[5]);
        if (id >= nextBillId) nextBillId = id + 1;
    }
    std::cout << "Loaded " << bills.size() << " bills.\n";
}

// --------------------------------------------------
// SAVE (CSV)
// --------------------------------------------------

void Hospital::savePatients(const std::string &file) {
    std::vector<std::string> header = {"id","name","age","gender","contact"};
    std::vector<std::vector<std::string>> rows;
    for (const auto &p : patients)
        rows.push_back({std::to_string(p.getId()), p.getName(), std::to_string(p.getAge()), p.getGender(), p.getContact()});
    CSV::writeCSV(file, header, rows);
}

void Hospital::saveDoctors(const std::string &file) {
    std::vector<std::string> header = {"id","name","specialty","contact"};
    std::vector<std::vector<std::string>> rows;
    for (const auto &d : doctors)
        rows.push_back({std::to_string(d.getId()), d.getName(), d.getSpecialty(), d.getContact()});
    CSV::writeCSV(file, header, rows);
}

void Hospital::saveAppointments(const std::string &file) {
    std::vector<std::string> header = {"id","patientId","doctorId","date","time"};
    std::vector<std::vector<std::string>> rows;
    for (const auto &a : appointments)
        rows.push_back({std::to_string(a.getId()), std::to_string(a.getPatientId()), std::to_string(a.getDoctorId()), a.getDate(), a.getTime()});
    CSV::writeCSV(file, header, rows);
}

void Hospital::saveBilling(const std::string &file) {
    std::vector<std::string> header = {"billId","appointmentId","doctorId","amount","description","date"};
    std::vector<std::vector<std::string>> rows;
    for (const auto &b : bills)
        rows.push_back({std::to_string(b.getBillId()), std::to_string(b.getAppointmentId()), std::to_string(b.getDoctorId()), std::to_string(b.getAmount()), b.getDescription(), b.getDate()});
    CSV::writeCSV(file, header, rows);
}
