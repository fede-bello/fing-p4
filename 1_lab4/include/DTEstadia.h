#ifndef DTESTADIA
#define DTESTADIA

#include<iostream>
#include<string>
#include"DTFecha.h"

class DTEstadia{
    private:
        int num;
        string texto;
        string respuesta;
    public:
        DTEstadia(int cod,string texto);
        //no se si se precisa esto
        int getCodigo();
        string getTexto();
        string getRespuesta();
        ~DTEstadia();
};


#endif