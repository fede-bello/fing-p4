#ifndef DTE
#define DTE

#include<iostream>
#include<string>
#include"DTEstadia.h"
#include "../../conceptos/include/Calificacion.h"

class DTEstadia{
    private:
        int identificador;
        DTFecha CheckIn;
        DTFecha CheckOut;
        
        //promo y costo ya no son necesarios
    public:
        DTEstadia(int identidicador,DTFecha CheckIn);
        DTEstadia(int identidicador,DTFecha CheckIn,DTFecha CheckOut);
        //no se si se precisa esto
        int getIdentificador();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        DTEstadia getDTEstadia();
        
        ~DTEstadia();
};

   
#endif