#ifndef CONTU
#define CONTU

#include<iostream>
#include<string>

class controladorUsuario{
    private:
        static controladorUsuario * instance;
        controladorUsuario();
    public:
        static controladorUsuario * getInstance();
};

#endif