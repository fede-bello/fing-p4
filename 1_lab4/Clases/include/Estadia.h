#ifndef EST
#define EST

#include<iostream>
#include<string>
#include"Calificacion.h"
#include "Huesped.h"
#include"../../DataType/include/DTEstadia.h"
#include"../../DataType/include/DTFecha.h"


class Estadia{
    private:
        int identificador;
        DTFecha CheckIn;
        DTFecha CheckOut;
        Calificacion *calif;
        Huesped *hues;
        //promo y costo ya no son necesarios
    public:
        Estadia();
        Estadia(int identificador,DTFecha CheckIn,DTFecha CheckOut);
        int getIdentificador();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        Calificacion* getCalificacion();
        DTEstadia getDTEstadia();
        Huesped* getHuesped();
        void setIdentificador(int identificador);
        void setCheckIn(DTFecha checkIn);
        void setCheckOut(DTFecha checkOut);
        void setCalificacion(Calificacion *calif);
        void setHuesped(Huesped *huesped);
        ~Estadia();
};


     

#endif