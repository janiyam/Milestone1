#include "../include/ReservationManager.h"
#include <iostream>

using namespace std;

ReservationManager::ReservationManager()
{
    head = nullptr;
}

ReservationManager::~ReservationManager()
{
    clear();
}

bool ReservationManager::createReservation(const Reservation& reservation)
{
    if (!validateReservation(reservation))
    {
        return false;
    }

    if (reservationExists(reservation.getReservationID()))
    {
        return false;
    }

    Node* newNode = new Node(reservation);

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = newNode;
    }

    return true;
}

bool ReservationManager::cancelReservation(int reservationID)
{
    if (head == nullptr)
    {
        return false;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr)
    {
        if (current->reservation.getReservationID() == reservationID)
        {
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

void ReservationManager::displayReservations() const
{
    if (head == nullptr)
    {
        cout << "No active reservations." << endl;
        return;
    }

    Node* current = head;

    while (current != nullptr)
    {
        current->reservation.display();
        cout << "------------------------" << endl;

        current = current->next;
    }
}

bool ReservationManager::reservationExists(int reservationID) const
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->reservation.getReservationID() == reservationID)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

bool ReservationManager::validateReservation(const Reservation& reservation) const
{
    // IDs must be positive
    if (reservation.getReservationID() <= 0)
        return false;

    if (reservation.getStudentID() <= 0)
        return false;

    // Student name must have at least 2 characters
    if (reservation.getStudentName().length() < 2)
        return false;

    // Resource ID must not be empty or whitespace
    if (reservation.getResourceID().empty())
        return false;

    // Date must follow a basic YYYY-MM-DD format (length check only)
    if (reservation.getReservationDate().length() < 8)
        return false;

    return true;
}


void ReservationManager::clear()
{
    Node* current = head;

    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}
