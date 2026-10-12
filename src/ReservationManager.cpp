#include "../include/ReservationManager.h"
#include <iostream>

ReservationManager::ReservationManager()
    : head(nullptr) {
}

ReservationManager::~ReservationManager() {
    clear();
}

bool ReservationManager::validateReservation(
    const Reservation& reservation) const {

    if (reservation.getReservationID() <= 0) {
        return false;
    }

    if (reservation.getStudentID() <= 0) {
        return false;
    }

    if (reservation.getStudentName().size() < 2) {
        return false;
    }

    if (reservation.getResourceID().empty()) {
        return false;
    }

    // Check the YYYY-MM-DD date format.
    std::string date = reservation.getReservationDate();

    if (date.size() != 10 ||
        date[4] != '-' ||
        date[7] != '-') {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            continue;
        }

        if (date[i] < '0' || date[i] > '9') {
            return false;
        }
    }

    return true;
}

bool ReservationManager::createReservation(
    const Reservation& reservation) {

    if (!validateReservation(reservation)) {
        return false;
    }

    if (reservationExists(
            reservation.getReservationID())) {
        return false;
    }

    Node* current = head;
    while (current != nullptr)
    {
        if (current->reservation.getResourceID() == reservation.getResourceID() &&
            current->reservation.getReservationDate() == reservation.getReservationDate())
        {
            return false;
        }

        current = current->next;
    }

    Node* newNode = new Node(reservation);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        tail->next = newNode;
    }

    return true;
}

bool ReservationManager::cancelReservation(
    int reservationID,
    CancellationHistory& history)
{
    Reservation canceled;

    if (!cancelReservation(reservationID, canceled))
    {
        return false;
    }

    history.push(canceled);
    return true;
}

bool ReservationManager::cancelReservation(int reservationID)
{
    Reservation canceled;
    return cancelReservation(reservationID, canceled);
}

bool ReservationManager::cancelReservation(
    int reservationID,
    Reservation& canceled)
{
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr)
    {
        if (current->reservation.getReservationID() == reservationID)
        {
            canceled = current->reservation;

            if (previous == nullptr)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            delete current;
            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

                head = current->next;
            } else {
                previous->next = current->next;
            }

            delete current;
            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

bool ReservationManager::restoreReservation(
    const Reservation& reservation) {

    return createReservation(reservation);
}

void ReservationManager::displayReservations() const {
    if (head == nullptr) {
        std::cout << "No active reservations.\n";
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        current->reservation.display();

        std::cout << "------------------------\n";

        current = current->next;
    }
}

bool ReservationManager::reservationExists(
    int reservationID) const {

    Node* current = head;

    // Hand-written linear search.
    while (current != nullptr) {
        if (current->reservation.getReservationID()
            == reservationID) {
            return true;
        }

        current = current->next;
    }

    return false;
}

bool ReservationManager::findReservation(
    int reservationID,
    Reservation& result) const {

    Node* current = head;

    // Hand-written linear search.
    while (current != nullptr) {
        if (current->reservation.getReservationID()
            == reservationID) {

            result = current->reservation;
            return true;
        }

        current = current->next;
    }

    return false;
}

// Counts every active reservation.
int ReservationManager::getTotalActiveReservations() const {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

// Counts active reservations for one resource.
int ReservationManager::countReservationsForResource(
    const std::string& resourceID) const {

    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        if (current->reservation.getResourceID()
            == resourceID) {
            count++;
        }

        current = current->next;
    }

    return count;
}

// Counts active reservations belonging to one student.
int ReservationManager::countReservationsForStudent(
    int studentID) const {

    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        if (current->reservation.getStudentID()
            == studentID) {
            count++;
        }

        current = current->next;
    }

    return count;
}

void ReservationManager::clear() {
    while (head != nullptr) {
        Node* nextNode = head->next;

        delete head;
        head = nextNode;
    }
}

int ReservationManager::getReservationCount() const
{
    int count = 0;
    Node* current = head;

    while (current != nullptr)
    {
        count++;
        current = current->next;
    }

    return count;
}

int ReservationManager::countForResource(const std::string& resourceID) const
{
    int count = 0;
    Node* current = head;

    while (current != nullptr)
    {
        if (current->reservation.getResourceID() == resourceID)
        {
            count++;
        }
        current = current->next;
    }

    return count;
}