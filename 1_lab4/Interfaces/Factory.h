#include "IcontroladorHostal.h"
#include "IcontroladorFecha.h"
#include "IcontroladorReserva.h"
#include "IcontroladorUsuario.h"

#include "../Controladores/include/controladorHostal.h"
#include "../Controladores/include/controladorFecha.h"
#include "../Controladores/include/controladorReserva.h"
#include "../Controladores/include/controladorUsuario.h"

class Factory{
    public:
        IcontroladorUsuario getIcontroladorUsuario();
        IcontroladorReserva getIcontroladorReserva();
        IcontroladorHostal getIcontroladorHostal();
        IcontroladorFecha getIcontroladorFecha();
};