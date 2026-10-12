#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include "Reservation.h"
#include <string>

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

public:

    ReservationManager();

    ~ReservationManager();

    bool createReservation(const Reservation& reservation);

    bool cancelReservation(int reservationID, CancellationHistory& history);

    void displayReservations() const;

    int getReservationCount() const;

    int countForResource(const std::string& resourceID) const;

    bool reservationExists(int reservationID) const;

    bool validateReservation(const Reservation& reservation) const;

private:

    void clear();

};

#endif
