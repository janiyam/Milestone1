#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <string>

class WaitingList
{
  private:
      struct Node
      {
          int studentID;
          std::string studentName;
          std::string resourceID;
          Node* next;
      };

      Node* front;
      Node* rear;

  public:
    WaitingList();
    ~WaitingList();


    void enqueue(int studentID,
                 const std::string& studentName,
                 const std::string& resourceID);

    bool dequeue(int& studentID,
                 std::string& studentName,
                 std::string& resourceID);

    ~WaitingList();


     void enqueue(int studentID,
                  const std::string& studentName,
                  const std::string& resourceID);


    bool isEmpty() const;

    void display() const;

    int countForResource(const std::string& resourceID) const;

};
#endif
