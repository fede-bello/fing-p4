#ifndef CONTR
#define CONTR

#include "../../Clases/include/Reserva.h"
#include "controladorFecha.h"
class ControladorReserva {
private:
    static ControladorReserva * instancia;
    ControladorReserva();
    
public:
    static ControladorReserva * getInstance();
    void ModificarReservaActual(DTReserva nueva);
    int indiceReserva=0;
    void operacion();
    ~ControladorReserva();
};


#endif