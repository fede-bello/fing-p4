#ifndef CONTF
#define CONTF
#include "../../DataType/include/DTFecha.h"

class controladorFecha{ //en los singleton los contructores son funciones privadas
private:
    DTFecha fechaActual; 
    controladorFecha(){
        this->fechaActual=DTFecha();
    }
    static controladorFecha cfecha;//el unico objeto tipo controladorFecha en el programa debe ser este.
public:
    static controladorFecha& getInstance(){
        return cfecha;
    };
    void ModificarFechaActual(DTFecha nuevafecha){
        this->fechaActual=nuevafecha;
    }
    ~controladorFecha(){};
};

controladorFecha controladorFecha:: cfecha;





#endif