#ifndef DTHAB
#define DTHAB


#include "DTReserva.h"//
#include"DTFecha.h"




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

#endif


