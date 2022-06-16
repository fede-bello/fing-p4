#ifndef IFECHA
#define IFECHA

#include"../../DataType/include/DTFecha.h"

class IcontroladorFecha{
    public:
        //virtual static controladorFecha * getInstance();
        //Vi que por alguna razon hay que poner=0 para que funcione
        virtual void ModificarFechaActual(DTFecha nueva)=0;
        virtual DTFecha getFechaActual()=0;
        virtual void operacion()=0;
        virtual ~IcontroladorFecha() {};

};

#endif