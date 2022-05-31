#ifndef DTCALIFICACION
#define DTCALIFICACION

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
        int getCodigo();
        string getTexto();
        string getRespuesta();
        ~DTCalificacion();
};


#endif
