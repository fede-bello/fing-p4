#ifndef DTEST
#define DTEST


#include"DTCalificacion.h"//
#include "DTFecha.h"


class DTEstadia{
    private:
        //Falta pseudo atributo para DTHuesped y DTCalificacion
        DTFecha CheckIn;
        DTFecha CheckOut;
        int identificador;
        
        //promo y costo ya no son necesarios
    public:
        DTEstadia();
        DTEstadia(int identificador,DTFecha CheckIn,DTFecha CheckOut);
        //no se si se precisa esto
        int getIdentificador();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        DTEstadia getDTEstadia();
        void imprimir();
        
        ~DTEstadia();
};

   
#endif