#ifndef DTUSE
#define DTUSE


#include "DTUsuario.h"
enum Cargo{
    Limpieza, Administracion, Infrasetructura, Recepcion
};

class DTEmpleado :public DTUsuario
{
private:
    Cargo tarea;
public:
    DTEmpleado(string nombre,string direccion,int telefono);
    ~DTEmpleado();
};





#endif