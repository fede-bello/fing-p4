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
    public:
        Calificacion(int cod,string texto);
        //no se si se precisa esto
        int getCodigo();
        string getTexto();
        string getRespuesta();
        ~Calificacion();
};


#endif
