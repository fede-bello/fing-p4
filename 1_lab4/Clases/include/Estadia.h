#ifndef EST
#define EST

#include<iostream>
#include<string>
#include"../../DataType/include/DTEstadia.h"
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
        int getidentificador();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        Calificacion* getCalificacion();
        DTEstadia getDTEstadia();
        void setidentificador(int identificador);
        void setCheckIn(DTFecha checkIn);
        void setCheckOut(DTFecha checkOut);
        void setCalificacion(Calificacion calif)
        ~Estadia();
};


     

#endif