#ifndef DTUSH
#define DTUSH


#include "DTUsuario.h"

class DTHuesped: public DTUsuario{
    private:
        bool esFinger;
    public:
        DTHuesped();
        DTHuesped(string Nombre,string Password, string Mail, bool esFinger);
        bool getEsFinger();
        virtual void imprimir();
        ~DTHuesped();
};


#endif


