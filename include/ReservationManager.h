#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include "Reservation.h"
#include <string>

class ReservationManager {
private:
    struct Node {
        Reservation reservation;
        Node* next;

        Node(const Reservation& value)
            : reservation(value), next(nullptr) {
        }
    };

    Node* head;

    void clear();

public:
    ReservationManager();
    ~ReservationManager();

    // Prevent copying the linked list accidentally.
    ReservationManager(const ReservationManager&) = delete;
    ReservationManager& operator=(
        const ReservationManager&) = delete;

    bool createReservation(const Reservation& reservation);

    bool cancelReservation(int reservationID, CancellationHistory& history);
    bool cancelReservation(int reservationID);
    bool cancelReservation(
        int reservationID,
        Reservation& canceled);

    bool restoreReservation(const Reservation& reservation);

    void displayReservations() const;

    int getReservationCount() const;

    int countForResource(const std::string& resourceID) const;

    bool reservationExists(int reservationID) const;

    bool validateReservation(
        const Reservation& reservation) const;

    bool findReservation(
        int reservationID,
        Reservation& result) const;

    // Functions used by reports.
    int getTotalActiveReservations() const;

    int countReservationsForResource(
        const std::string& resourceID) const;

    int countReservationsForStudent(int studentID) const;
};

#endif
