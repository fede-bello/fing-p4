#ifndef DTCAL
#define DTCAL

#include<iostream>
#include<string>
#include"DTFecha.h"

class DTCalificacion{
    private:
        int num;
        string texto;
        string respuesta;
        DTFecha realizada;
    public:
        DTCalificacion(int cod,string texto,DTFecha realizada);
        DTCalificacion(int cod,string texto,DTFecha realizada,string respuesta);
        //no se si se precisa esto
        int getNum();
        string getTexto();
        DTFecha getFecha();
        string getRespuesta();
        void setRespuesta(string respuesta);
        ~DTCalificacion();
};


#endif
