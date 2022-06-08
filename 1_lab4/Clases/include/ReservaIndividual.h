#ifndef RESI
#define RESI

#include "Reserva.h"
#include "../../DataType/include/DTReservaIndividual.h"
#include "../../DataType/include/DTFecha.h"

class ReservaIndividual: public Reserva{
    public:
        //constructor
        ReservaIndividual();
        ReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado);
        //destructor
        ~ReservaIndividual();
};

#endif