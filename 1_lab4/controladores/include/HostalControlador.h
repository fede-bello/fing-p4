#ifndef CONTH
#define CONTH

#include"../../DataType/include/DTHostal.h"

class HostalControlador{ //en los singleton los contructores son funciones privadas
private:
    HostalControlador();
    static HostalControlador cHostal;//el unico objeto tipo HostalControlador en el programa debe ser este.
public:
    static HostalControlador& getInstance(){
        return cHostal;
    };
    int indiceHostal=0;
    void ModificarHostalActual(DTHostal nuevaHostal);
    ~HostalControlador();
};

HostalControlador HostalControlador:: cHostal;


#endif