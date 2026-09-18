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

bool ReservationManager::validateReservation(
    const Reservation& reservation) const
{
    if (reservation.getReservationID() <= 0)
    {
        return false;
    }

    if (reservation.getStudentID() <= 0)
    {
        return false;
    }

    if (reservation.getStudentName().empty())
    {
        return false;
    }

    if (reservation.getResourceID().empty())
    {
        return false;
    }

    if (reservation.getReservationDate().empty())
    {
        return false;
    }

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
