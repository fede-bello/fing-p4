#ifndef CONTF
#define CONTF
#include "../../DataType/include/DTFecha.h"
#include "../../Interfaces/include/IcontroladorFecha.h"

class controladorFecha :public IcontroladorFecha {
private:
    static controladorFecha * instancia;
    controladorFecha();
    DTFecha fechaActual = DTFecha();
    
public:
    static controladorFecha * getInstance();
    void ModificarFechaActual(DTFecha nueva);
    DTFecha getFechaActual();
    void operacion();
    ~controladorFecha();
};

#endif