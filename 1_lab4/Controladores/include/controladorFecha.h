#ifndef CONTF
#define CONTF
#include "../../DataType/include/DTFecha.h"

class ControladorFecha {
private:
    static ControladorFecha * instancia;
    ControladorFecha();
    DTFecha fechaActual = DTFecha();
    
public:
    static ControladorFecha * getInstance();
    void ModificarFechaActual(DTFecha nueva);
    DTFecha getFechaActual();
    void operacion();
    ~ControladorFecha();
};












#endif