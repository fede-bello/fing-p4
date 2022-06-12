#ifndef CONTR
#define CONTR

#include "../../Clases/include/Reserva.h"
#include "controladorFecha.h"
class controladorReserva {
private:
    static controladorReserva * instancia;
    controladorReserva();
    map<int,Reserva*> MapaReserva;
    DTReserva *ReservaGuardada;
public:
    static controladorReserva * getInstance();
    void ModificarReservaActual(DTReserva nueva);
    ~controladorReserva();
    void liberar();
};


#endif