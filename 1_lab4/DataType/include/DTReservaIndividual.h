
#ifndef DTRESI
#define DTRESI

#include"DTReserva.h"


class DTReservaIndividual: public DTReserva{
    public:
        //constructores
        DTReservaIndividual();
        DTReservaIndividual(int Codigo , DTFecha CheckIn, DTFecha CheckOut, EstadoReserva estado, float Costo);
        //destructor
        ~DTReservaIndividual();
};
#endif
