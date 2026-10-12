#include "../include/Reservation.h"
#include <iostream>

Reservation::Reservation()
    : reservationID(0),
      studentID(0),
      studentName(""),
      resourceID(""),
      reservationDate("") {
}

Reservation::Reservation(
    int id,
    int student,
    const std::string& name,
    const std::string& resource,
    const std::string& date)
    : reservationID(id),
      studentID(student),
      studentName(name),
      resourceID(resource),
      reservationDate(date) {
}

int Reservation::getReservationID() const {
    return reservationID;
}

int Reservation::getStudentID() const {
    return studentID;
}

std::string Reservation::getStudentName() const {
    return studentName;
}

std::string Reservation::getResourceID() const {
    return resourceID;
}

std::string Reservation::getReservationDate() const {
    return reservationDate;
}

void Reservation::display() const {
    std::cout << "Reservation ID: "
              << reservationID << '\n';

    std::cout << "Student ID: "
              << studentID << '\n';

    std::cout << "Student Name: "
              << studentName << '\n';

    std::cout << "Resource ID: "
              << resourceID << '\n';

    std::cout << "Reservation Date: "
              << reservationDate << '\n';
}
