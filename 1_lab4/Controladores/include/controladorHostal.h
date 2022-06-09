#ifndef CONTH
#define CONTH

#include"../../Clases/include/Hostal.h"
#include"ControladorReserva.h"

class ControladorHostal{ //en los singleton los contructores son funciones privadas
private:
    ControladorHostal();
    static ControladorHostal cHostal;//el unico objeto tipo ControladorHostal en el programa debe ser este.
public:
    static ControladorHostal& getInstance(){
        return cHostal;
    };
    int indiceHostal=0;
    void ModificarHostalActual(DTHostal nuevaHostal);
    ~ControladorHostal();
};

ControladorHostal ControladorHostal:: cHostal;


#endif