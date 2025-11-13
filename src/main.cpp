#include <iostream>
#include "Hospital.h"

int main() {
    Hospital hosp;
    try {
        auto p = hosp.addPatient("Alice", 30, "F", "999999999");
        auto d = hosp.addDoctor("Dr. Bob", "Cardiology");
        auto a = hosp.bookAppointment(p.getId(), d.getId(), "2025-11-20", "10:00");
        std::cout << "Booked appointment ID: " << a.getId() << "\n";
    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }
    return 0;
}
