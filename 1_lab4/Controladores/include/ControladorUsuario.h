#ifndef CONTU
#define CONTU

#include "../../Clases/include/Usuario.h"
#include "ControladorHostal.h"

class ControladorUsuario {
private:
    static ControladorUsuario * instancia;
    ControladorUsuario();
    
public:
    static ControladorUsuario *getInstance();
    int indiceUsuario=0;
    void operacion();
    ~ControladorUsuario();
};

#endif