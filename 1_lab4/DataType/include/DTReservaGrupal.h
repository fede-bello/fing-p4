
#ifndef DTRESG
#define DTRESG

#include "DTHuesped.h"//
#include"DTReserva.h"

class DTReservaGrupal: public DTReserva{
    private:
        //Falta pseudo atributo para DTHuesped
        int Cantidad;
        //Van los huespedes asociados?
    public:
        //constructores
        DTReservaGrupal();
        DTReservaGrupal(int Codigo , DTFecha CheckIn, DTFecha CheckOut, EstadoReserva estado, float Costo, int Cantidad);
        /*DTHuesped** getHuespedes();*/
        //getter
        int getCantidad();
        //destructor
        ~DTReservaGrupal();
};

#endif
