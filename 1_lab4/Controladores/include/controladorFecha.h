#ifndef CONTF
#define CONTF
#include "../../DataType/include/DTFecha.h"

class FechaControlador{ //en los singleton los contructores son funciones privadas
private:
    DTFecha fechaActual; 
    FechaControlador(){
        this->fechaActual=DTFecha();
    }
    static FechaControlador cfecha;//el unico objeto tipo FechaControlador en el programa debe ser este.
public:
    static FechaControlador& getInstance(){
        return cfecha;
    };
    void ModificarFechaActual(DTFecha nuevafecha);

    ~FechaControlador(){};
};

FechaControlador FechaControlador:: cfecha;





#endif