#ifndef CONTR
#define CONTR

#include "Reserva.h"

class ReservaControlador {
private:
    static ReservaControlador * instancia;
    ReservaControlador();
    
public:
    static ReservaControlador * getInstance();
    void ModificarReservaActual(DTReserva nueva);
    int indiceReserva=0;
    void operacion();
    ~ReservaControlador();
};


#endif