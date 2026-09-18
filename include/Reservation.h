class Reservation
{
private:
    int reservationID;
    int studentID;
    string studentName;
    string resourceID;
    string reservationDate;

public:
    // constructor
    Reservation(...);

    // getters
    int getReservationID();
    int getStudentID();
    string getStudentName();
    string getResourceID();
    string getReservationDate();
};
