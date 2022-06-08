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
        Estadia(int identidicador,DTFecha CheckIn);
        Estadia(int identidicador,DTFecha CheckIn,DTFecha CheckOut);
        //no se si se precisa esto
        int getidentificador();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        Calificacion* getCalificacion();
        DTEstadia getDTEstadia();
        Huesped* getHuesped();
        void setidentificador(int identificador);
        void setCheckIn(DTFecha checkIn);
        void setCheckOut(DTFecha checkOut);
        void setCalificacion(Calificacion calif);
        void setHuesped(Huesped *huesped);
        ~Estadia();
};


     

#endif