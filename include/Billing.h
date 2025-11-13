#pragma once
#include <string>
#include <iostream>

class Billing {
private:
    int billId;
    int appointmentId;
    int doctorId;
    double amount;
    std::string description;
    std::string date;

public:
    Billing() : billId(0), appointmentId(0), doctorId(0), amount(0.0) {}

    Billing(int billId, int appointmentId, int doctorId,
            double amount, const std::string &description, const std::string &date)
        : billId(billId),
          appointmentId(appointmentId),
          doctorId(doctorId),
          amount(amount),
          description(description),
          date(date) {}

    int getBillId() const { return billId; }
    int getAppointmentId() const { return appointmentId; }
    int getDoctorId() const { return doctorId; }
    double getAmount() const { return amount; }
    std::string getDescription() const { return description; }
    std::string getDate() const { return date; }

    friend std::ostream &operator<<(std::ostream &os, const Billing &b) {
        os << "Billing[BillID=" << b.billId
           << ", AppointmentID=" << b.appointmentId
           << ", DoctorID=" << b.doctorId
           << ", Amount=" << b.amount
           << ", Description=" << b.description
           << ", Date=" << b.date << "]";
        return os;
    }
};
