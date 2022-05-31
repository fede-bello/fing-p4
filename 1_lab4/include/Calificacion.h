#ifndef CALIFICACION
#define CALIFICACION

#include<iostream>
#include<string>
#include"DTFecha.h"

class Calificacion{
    private:
        int num;
        string texto;
        string respuesta;
        DTFecha realizada;
    public:
        Calificacion(int cod,string texto,DTFecha realizada);
        //no se si se precisa esto
        int getCodigo();
        string getTexto();
        string getRespuesta();
        ~Calificacion();
};


#endif
