#ifndef E
#define E

#include<iostream>
#include<string>
#include"DTEstadia.h"
#include"Calificacion.h"

class Estadia{
    private:
        int identificador;
        DTFecha CheckIn;
        DTFecha CheckOut;
        Calificacion *calificacion;
        //promo y costo ya no son necesarios
    public:
        Estadia(int identidicador,DTFecha CheckIn);
        Estadia(int identidicador,DTFecha CheckIn,DTFecha CheckOut);
        //no se si se precisa esto
        int getIdentificador();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        void setCheckOut();
        Calificacion getCalificacion();
        DTEstadia getDTEstadia();
        ~Estadia();
};


     

#endif