cmake_minimum_required(VERSION 3.10)
project(hospital-management-system-cpp)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
    src/main.cpp
    src/Hospital.cpp
    src/Patient.cpp
    src/Doctor.cpp
    src/Appointment.cpp
    src/Billing.cpp
    src/CSVUtils.cpp
)

include_directories(include)

add_executable(hms ${SOURCE_FILES})
