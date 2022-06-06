#ifndef HAB
#define HAB

#include<iostream>
#include<string>
#include"../../DataType/include/DTFecha.h"
#include "../../DataType/include/DTHabitacion.h"

class Habitacion{
    private:
        int numero=0, capacidad=0;
        float precio=0.0;
    public:
        Habitacion();
        Habitacion(int numero, int capacidad, float precio);
        void setNum(int numero);
        void setCap(int capacidad);
        void setPrecio(float precio);
        int getNum();
        int getCap();
        float getPrecio();
        ~Habitacion();
};

#endif