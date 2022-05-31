#ifndef RI
#define RI

#include "Reserva.h"

class ReservaIndividual: public Reserva{
    private:
        bool pagado;
    public:
        //constructor
        ReservaIndividual();
        ReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int cantidad,bool pagado);
        //destructor
        ~ReservaIndividual();
        //operaciones
        void setPagado(bool pagado);
        bool getPagado();
};

#endif