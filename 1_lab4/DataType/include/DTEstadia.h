#ifndef DTEST
#define DTEST

#include<iostream>
#include<string>
#include "DTFecha.h"

class DTEstadia{
    private:
        DTFecha CheckIn;
        DTFecha CheckOut;
        int identificador;
        
        //promo y costo ya no son necesarios
    public:
        DTEstadia();
        DTEstadia(int identidicador,DTFecha CheckIn,DTFecha CheckOut);
        //no se si se precisa esto
        int getIdentificador();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        DTEstadia getDTEstadia();
        
        ~DTEstadia();
};

   
#endif