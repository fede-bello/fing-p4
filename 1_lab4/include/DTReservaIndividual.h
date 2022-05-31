
#ifndef DTRESERVAINDIVIDUAL
#define DTRESERVAINDIVIDUAL
#include"DTReserva.h"

class DTReservaIndividual: public DTReserva{
    private:
        bool pagado;
    public:
        //constructores
        bool getPagado();
        DTReservaIndividual();
        DTReservaIndividual(int habitacion , DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo , int codigo, int cantidad,bool pagado);
        //destructor
        ~DTReservaIndividual();
};
#endif
