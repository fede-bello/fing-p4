#ifndef CONTF
#define CONTF
#include "../../DataType/include/DTFecha.h"

class FechaControlador {
private:
    static FechaControlador * instancia;
    FechaControlador();
    DTFecha *fechaActual=NULL;
    
public:
    static FechaControlador * getInstance();
    void ModificarFechaActual(DTFecha nueva);
    DTFecha* getFechaActual();
    void operacion();
    ~FechaControlador();
};












#endif