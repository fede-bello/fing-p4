#ifndef DTE
#define DTE

#include<iostream>
#include<string>
#include"DTFecha.h"

class DTEstadia{
    private:
        int identificador;
        DTFecha CheckIn;
        DTFecha CheckOut;
        //promo y costo ya no son necesarios
    public:
        DTEstadia(int identidicador,DTFecha CheckIn);
        //no se si se precisa esto
        int getCodigo();
        string getTexto();
        string getRespuesta();
        ~DTEstadia();
};


#endif