#include "../include/ReservationManger.h"
#include "../include/Reservation.h"
#include "../include/WaitingList.h"
#include "../include/CancellationHistory.h"

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
  ReservationManager manager;
  WaitingList waitingList;
  CancellationHistory cancellationHistory;

  int choice;

  do
  {
    cout << "\n======== Campus Resource Reservation System =======\n";
    cout << "1. Create Reservation\n";
    cout << "2. Cancel Reservation\n";
    cout << "3. View Active Reservations\n";
    cout << "4. Search Reservation\n";
    cout << "5. Add Student to Waiting List\n";
    cout << "6. Remove Student from Waiting List\n";
    cout << "7. View Waiting List\n";
    cout << "8. View Cancellation History\n";
    cout << "9. Exit\n";
    cout << "Enter Choice: ";

    cin >> choice;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice.\n";
        continue;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice)
    {
        case 1:
        {
            int reservationID;
            int studentID;
            string studentName;
            string resourceID;
            string reservationDate;

            cout << "Reservation ID: ";
            cin >> reservationID;

            cout << "Student ID: ";
            cin >> studentID;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Student Name: ";
            getline(cin, studentName);

            cout << "Resource ID: ";
            getline(cin, resourceID);

            cout << "Reservation Date: ";
            getline(cin, reservationDate);

            Reservation reservation(reservationID, studentID, studentName,
                                    resourceID, reservationDate);

            if (manager.createReservation(reservation))
            {
                cout << "Reservation created successfully.\n";
            }
            else
            {
                cout << "Could not create reservation.\n";
            }
            break;
        }
        case 2:
        {
            int reservationID;
            cout << "Cancelled Reservation ID: ";
            cin >> reservationID;

            if (manager.cancelReservation(reservationID))
            {
                cout << "Reserved cancelled.\n";
            }
            else
            {
                cout << "Reservation not found.\n";
            }
            break;
        }

        case 3: 
            manager.displayReservation();
            break;

        case 4:
        {
            int id;
            cout << "Reservation ID to search: ";
            cin >> id;

            if (manager.reservationExists(id))
              cout << "Reservation exists.\n";
            else
              cout << "Reservation not found.\n";
            break;
        }
        case 5:
              addStudentToWaitingList(waitingList);
              break;
        case 6:
        {
            int id;
            string name, resource;

            if (waitingList.dequeue(id, name, resource))
              cout << "Student removed from waiting list.\n";
            else
               cout << "Waiting list is empty.\n";
            break;
        }

        case 7:
              waitingList.display();
              break;
        case 8:
              cancellationHistory.display();
              break;
        case 9:
              cout << "Exit...\n";
              break;
        default:
              cout << "Invalid choice.\n";
    }
  } while (choice != 9);
  
  return 0;
}
    
