#ifndef DTUSH
#define DTUSH

#include<iostream>
#include<string>
#include "DTUsuario.h"


class DTHuesped:public DTUsuario{
    private:
        bool esFinger;
    public:
        DTHuesped(string nombre, string email,string password, bool esFinger);
        void setEsFinger();
        bool getEsFinger();
        ~DTHuesped();
};


#endif


