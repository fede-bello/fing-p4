#ifndef HAB
#define HAB

#include<iostream>
#include<string>
#include "Reserva.h"
#include "../../DataType/include/DTHabitacion.h"

class Habitacion{
    private:
        int numero=0, capacidad=0;
        float precio=0.0;
        Reserva* res;
    public:
        Habitacion();
        Habitacion(int numero, int capacidad, float precio);
        int getNum();
        int getCap();
        float getPrecio();
        Reserva* getReserva();
        void setNum(int numero);
        void setCap(int capacidad);
        void setPrecio(float precio);
        void setReserva(Reserva *res);
        ~Habitacion();
};

#endif       