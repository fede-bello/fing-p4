#ifndef CONTR
#define CONTR

#include "../../Clases/include/Reserva.h"
#include "controladorFecha.h"
class ControladorReserva {
private:
    static ControladorReserva * instancia;
    ControladorReserva();
    map<int,Reserva> MapaReserva;
    
public:
    static ControladorReserva * getInstance();
    void ModificarReservaActual(DTReserva nueva);
    ~ControladorReserva();
};


#endif