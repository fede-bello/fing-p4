#ifndef RESERVAGRUPAL
#define RESERVAGRUPAL

#include "Reserva.h"

class ReservaGrupal: public Reserva{ 
    private:
        Huesped** huespedes;
    public:
        //constructor
        ReservaGrupal();
        ReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int cantidad,Huesped **Arreglo);
        //destructor
        ~ReservaGrupal();
        //operaciones
        Huesped** getHuespedes();
        void setHuespedes(Huesped** arreglo_huespedes);       

        virtual float calcularCosto();
};

#endif