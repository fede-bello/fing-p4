#ifndef CONTU
#define CONTU

<<<<<<< HEAD
#include "../../conceptos/include/Usuario.h"

class UsuarioControlador {
private:
    static UsuarioControlador * instancia;
    UsuarioControlador();
    
public:
    static UsuarioControlador *getInstance();
    int indiceUsuario=0;
    void operacion();
    ~UsuarioControlador();
=======
#include<iostream>
#include<string>

class controladorUsuario{
    private:
        static controladorUsuario * instance;
        controladorUsuario();
    public:
        static controladorUsuario * getInstance();
>>>>>>> 8f76a6c697dfd888afeabe5e95250cbd1f388278
};

#endif