#include <iostream>
#include "Hospital.h"

int main() {
    Hospital hosp;

    try {
        hosp.loadPatients("data/patients.csv");
        hosp.loadDoctors("data/doctors.csv");
        hosp.loadAppointments("data/appointments.csv");
        hosp.loadBilling("data/billing.csv");

        std::cout << "\n--- DATABASE LOADED SUCCESSFULLY ---\n\n";
    }
    catch (const std::exception &ex) {
        std::cerr << "Error loading data: " << ex.what() << std::endl;
        return 1;
    }

    // Sample output to verify everything works
    std::cout << "Total appointments loaded: " << hosp.getAllAppointments().size() << "\n";
    std::cout << "Total bills loaded: " << hosp.getAllBills().size() << "\n\n";

    std::cout << "Sample appointments:\n";
    for (const auto &a : hosp.getAllAppointments()) {
        std::cout << a << "\n";
    }

    std::cout << "\nSample bills:\n";
    for (const auto &b : hosp.getAllBills()) {
        std::cout << b << "\n";
    }

    return 0;
}
