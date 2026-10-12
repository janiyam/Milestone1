#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class Reservation {
private:
    int reservationID;
    int studentID;
    std::string studentName;
    std::string resourceID;
    std::string reservationDate;

public:
    Reservation();

    Reservation(int reservationID,
                int studentID,
                const std::string& studentName,
                const std::string& resourceID,
                const std::string& reservationDate);

    int getReservationID() const;
    int getStudentID() const;
    std::string getStudentName() const;
    std::string getResourceID() const;
    std::string getReservationDate() const;

    void display() const;
};

#endif
