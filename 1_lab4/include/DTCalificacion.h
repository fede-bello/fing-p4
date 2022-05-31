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
    public:
        DTCalificacion(int cod,string texto);
        //no se si se precisa esto
        int getCodigo();
        string getTexto();
        string getRespuesta();
        ~DTCalificacion();
};


#endif
