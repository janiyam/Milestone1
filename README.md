# Campus Resource Reservation System

## Project Overview

This project is a Campus Resource Reservation System created in C++. The purpose of the program is to allow students to reserve campus resources and manage active reservations. The project also uses different data structures to manage reservations, waiting lists, and cancellation history.

## Features

The system is designed to support the following features:

- Load campus resource information from a file
- Display available campus resources
- Create and cancel reservations
- Display active reservations
- Validate reservation information
- Add students to a waiting list when needed
- Keep track of cancelled reservations
- Restore the most recently cancelled reservation

## Data Structures

The project uses three main data structures.

### Linked List

One linked list is used to store all active reservations in the system. Each reservation contains information such as the reservation ID, student ID, student name, resource ID, and reservation date.

### Queue

A queue is used for the waiting list. Students are processed in FIFO (First In, First Out) order.

### Stack

A stack is used to store cancelled reservations. This allows the most recently cancelled reservation to be restored using LIFO (Last In, First Out) order.

## Resource Management

The Resource Management portion of the project loads resource information from `data/resources.txt`.

Each resource contains:

- Resource ID
- Resource name
- Location
- Capacity

The ResourceManager class can load resources, display resource information, check whether a resource ID exists, and provide resource information to other parts of the program.

The resource file uses the following format:

ResourceID|ResourceName|Location|Capacity

Example:

R001|Study Room A|Library|10

## Project Files

- `include/` - Header files for the project classes
- `src/` - C++ implementation files
- `data/resources.txt` - Campus resource information
- `data/reservations.txt` - Reservation data

## Compiling

The project is designed to compile and run on the UNT CSE CELL machines using g++.

The final compilation command may depend on which source files are included in the completed version of the project.

Example:

g++ -std=c++11 src/*.cpp -o reservationSystem

To run the program:

./reservationSystem

## Testing

The completed system should be tested for:

- Loading resource information from a file
- Displaying resources
- Creating reservations
- Cancelling reservations
- Processing the waiting list
- Restoring cancelled reservations
- Handling invalid input

## GitHub Collaboration

Each team member works on their assigned portion of the project using their own GitHub account. Feature branches and meaningful commits are used so individual contributions can be tracked before changes are merged into the main branch.

## Milestone 1

This repository contains the work completed for Milestone 1 of the Campus Resource Reservation System.
