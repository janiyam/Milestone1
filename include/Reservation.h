#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
using namespace std;

class Reservation
{
private:
    int reservationID;
    int studentID;
    string studentName;
    string resourceID;
    string reservationDate;

public:
    // default constructor
    Reservation();

    // constructor
    Reservation(int reservationID,
                int studentID,
                string studentName,
                string resourceID,
                string reservationDate);

    // getters
    int getReservationID() const;
    int getStudentID() const;
    string getStudentName() const;
    string getResourceID() const;
    string getReservationDate() const;

    // display reservation
    void display() const
};
#endif
