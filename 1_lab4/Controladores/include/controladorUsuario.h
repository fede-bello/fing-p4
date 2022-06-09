#ifndef CONTU
#define CONTU

#include "../../Clases/include/Usuario.h"
#include "controladorHostal.h"
class controladorUsuario{
    private:
        static controladorUsuario * instance;
        controladorUsuario();
    public:
        static controladorUsuario * getInstance();

};

#endif
