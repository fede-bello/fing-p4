#ifndef FACTORY
#define FACTORY

#include "IcontroladorHostal.h"
#include "IcontroladorFecha.h"
#include "IcontroladorReserva.h"
#include "IcontroladorUsuario.h"

#include "../..//Controladores/include/controladorHostal.h"
#include "../../Controladores/include/controladorFecha.h"
#include "../../Controladores/include/controladorReserva.h"
#include "../../Controladores/include/controladorUsuario.h"

class Factory{
    private:
        static Factory * instancia;
        Factory();
    public:
        static Factory * getInstancia();
<<<<<<< HEAD
        IcontroladorUsuario* getIcontroladorUsuario();
=======
        controladorUsuario* getIcontroladorUsuario();
>>>>>>> e20df699c27dc1fd49e438ad9b17d05191c42393
        IcontroladorReserva* getIcontroladorReserva();
        IcontroladorHostal* getIcontroladorHostal();
        IcontroladorFecha* getIcontroladorFecha();
};
#endif