#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class Reservation
{
private:
    int reservationID;
    int studentID;
    std::string studentName;
    std::string resourceID;
    std::string reservationDate;

public:
    // default constructor
    Reservation();

    // constructor
    Reservation(int reservationID,
                int studentID,
                std::string studentName,
                std::string resourceID,
                std::string reservationDate);

    // getters
    int getReservationID() const;
    int getStudentID() const;
    std::string getStudentName() const;
    std::string getResourceID() const;
    std::string getReservationDate() const;

    // display reservation
    void display() const;
};
#endif
