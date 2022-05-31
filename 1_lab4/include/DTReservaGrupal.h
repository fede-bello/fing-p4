
#ifndef DTRG
#define DTRG
#include"DTReserva.h"

class DTReservaGrupal: public DTReserva{
    private:
        DTHuesped **huespedes;
    public:
        //constructores
        DTReservaGrupal();
        DTReservaGrupal(int habitacion , DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo , int codigo, int cantidad,DTHuesped **Arreglo);
        DTHuesped** getHuespedes();
        //destructor
        ~DTReservaGrupal();
};

#endif