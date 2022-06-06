#ifndef CONTU
#define CONTU

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
};

#endif