#pragma once
#include <string>
#include <iostream>

class Billing {
private:
    int billId;
    int appointmentId;
    int doctorId;
    double amount;              // amount in rupees
    std::string description;
    std::string date;

public:
    Billing() : billId(0), appointmentId(0), doctorId(0), amount(0.0), description(), date() {}

    Billing(int billId, int appointmentId, int doctorId,
            double amount, const std::string &description, const std::string &date)
        : billId(billId),
          appointmentId(appointmentId),
          doctorId(doctorId),
          amount(amount),
          description(description),
          date(date) {}

    int getBillId() const noexcept { return billId; }
    int getAppointmentId() const noexcept { return appointmentId; }
    int getDoctorId() const noexcept { return doctorId; }
    double getAmount() const noexcept { return amount; }
    const std::string &getDescription() const noexcept { return description; }
    const std::string &getDate() const noexcept { return date; }

    inline friend std::ostream &operator<<(std::ostream &os, const Billing &b) {
        // use UTF-8 rupee sign
        os << "Billing[BillID=" << b.billId
           << ", AppointmentID=" << b.appointmentId
           << ", DoctorID=" << b.doctorId
           << ", Amount=₹" << static_cast<long long>(b.amount)
           << ", Description=" << b.description
           << ", Date=" << b.date << "]";
        return os;
    }
};
