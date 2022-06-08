#ifndef DTHAB
#define DTHAB

#include<iostream>
#include<string>
#include "DTReserva.h"//
#include"DTFecha.h"

using namespace std;


class DTHabitacion{
    private:
        //Falta pseudo atributo para DTReserva
        int Numero, Capacidad;
        float Precio;
    public:
        DTHabitacion();
        DTHabitacion(int Numero, int Capacidad, float Precio);
        int getNumero();
        int getCapacidad();
        float getPrecio();
        bool operator==(const DTHabitacion &otro) const;
        ~DTHabitacion();
};

inline ostream &operator<< (ostream& o, DTHabitacion * hab){
	return o<<"Número habitación: "<< hab->getNumero()<<endl<< "Capacidad habitación: " << hab->getCapacidad() <<endl<< "Costo: $"<<hab->getPrecio()<<endl;
}

#endif


