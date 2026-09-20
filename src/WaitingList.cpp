#include ".../include/WaitingList.h"

#include <iostream>
using namespace std;

WaitingList::WaitingList();
{
  front = nullptr;
  rear = nullptr;
}

void WaitingList::enqueue(int studentID, const string& studentName, const string& resourceID);
{
  Node* newNode = new Node

  newNode->studentID = studentID;
  newNode->studentName = studentaname;
  newNode->resourceID = resourceID;
  newNode->next = nullptr;

  if (rear == nullptr)
  {
    front = newNode;
    rear = newNode;
  }
  else
  {
    rear->next = newNode;
    rear = newNode;
  }
}

bool WaitingList::dequeue(int& studentID, string& studentName, string& resourceID);
{
  if (fornt == nullptr)
  {
    return false;
  }

  Node* temp = front;

  studentID = temp->studentID;
  studentName = temp->studentName;
  resourceID = temp->resourceID;

  front = front->next;

  if (front == nullptr)
  {
      rear = nullptr;
  }
  delete temp;
  return true;
}

bool WaitingList::isEmpty() const
{
  return front == nullptr;
}

void WaitingList::display() const
{
  if (front == nullptr)
  {
      cout << "Waisting list is empty." << endl;
      return;
  }
  Node* current = front;

  while (current != nullptr)
  {
      cout << "Student ID: " << current->studentID << endl;
      cout << "Student Name: " << current->studentName << endl;
      cout << "Resource ID: " << current->resourceID << endl;
      cout << "-------------------------" << endl;

      current = current->next;
  }
}
