#ifndef RESI
#define RESI

#include "Reserva.h"

class ReservaIndividual: public Reserva{
    public:
        //constructor
        ReservaIndividual();
        ReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado,float costo);
        //destructor
        ~ReservaIndividual();
};

#endif