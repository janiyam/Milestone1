#include ".../include/CancellationHistory.h"
#include <iostream>
using namespace std;

CancellationHistory::CancellationHistory()
{
  top == nullptr;
}

CancellationHistory::~CancellationHistory()
{
  while (top != nullptr)
  {
    Node* temp = top;
    top = top->next;
    delete temp;
  }
}

void CancellationHistory::push(const Reservation& reservation)
{
  Node* newNode = new Node;
  newNode->data = reservation;
  newNode->next = top;
  top = newNode;
}

bool CancellationHistory::pop(Reservation& reservation)
{
  if (top == nullptr)
  {
    return false;
  }
  Node* temp = top;

  reservation = temp->data;
  top = top->next;
  delete temp;
  return true;
}

bool CancellationHistory::isEmpty() const;
{
  return top == nullptr;
}

void CancellationHistory::display() const;
{
  if (top == nullptr)
  {
    cout << "Cancellation History is empty." << endl;
    return;
  }

    Node* current = top;

    while (current != nullptr)
    {
      current->data.display();
      cout << "----------------------------" << endl;

      current = current->next;
    }
  }
