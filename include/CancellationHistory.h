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

  CancellationHistory(const CancellationHistory&) = delete;
  CancellationHistory& operator=(const CancellationHistory&) = delete;

  void push(const Reservation& reservation);

  bool pop(Reservation& reservation);

  bool isEmpty() const;

  void display() const;
};
#endif
