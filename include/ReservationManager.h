#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include "Reservation.h"
#include "WaitingList.h"
#include "CancellationHistory.h"

class ReservationManager
{
private:

    struct Node
    {
        Reservation reservation;
        Node* next;

        Node(const Reservation& res)
        {
            reservation = res;
            next = nullptr;
        }
    };

    Node* head;

    WaitingList waitingList;
    CancellationHistory cancellationHistory;

public:

    ReservationManager();

    ~ReservationManager();

    bool createReservation(const Reservation& reservation);

    bool cancelReservation(int reservationID);

    void displayReservations() const;

    bool reservationExists(int reservationID) const;

    bool validateReservation(const Reservation& reservation) const;

    void addToWaitingList(int studentID, 
                          const std::string& studentName, 
                          const std::string& resourceID);

    void processWaitingList();

    void displayWaitingList();

    bool undoCancellation();

    void displayCancellationHistory() const;

private:

    void clear();

    void insertReservation(const Reservation& reservation);
};

#endif
