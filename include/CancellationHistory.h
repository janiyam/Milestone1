#ifndef CANCELLATIONHISTORY_H
#define CANCELLATIONHISTORY_H

#include "Reservation.h"

class CancellationHistory
{
private:
  struct Node
  {
    Reservation data;
    Node* next;
  };
    Node* top;

public:
  CancellationHistory();

  ~CancellationHistory();

  void push(const Reservation& reservation);

  bool pop(Reservation& reservation);

  bool isEmpty() const;

  void display() const;
};
#endif
