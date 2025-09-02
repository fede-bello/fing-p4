# Programming 4 – Lab 4 (FIng, Udelar)

Small C++ system to manage hostels (rooms, reservations, stays, ratings, and users) using classes, controllers, interfaces, and data types (DT).

## Requirements

- g++
- make

## Build

- make testing

## Run

- ./testing

## Clean

- make clean

## Estructura

- Clases/: core domain classes (.h/.cpp) like `Hostal`, `Habitacion`, `Reserva`, etc.
- Controladores/: controllers encapsulating application use-cases.
- DataType/: lightweight data transfer types (DTs/DTOs) used by interfaces.
- Interfaces/: public interfaces and `Factory` to obtain controllers.
- main.cpp: console UI / entry point with test menu.
- Makefile: build rules (target `testing`, `clean`).
