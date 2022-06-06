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
    DTEmpleado(string nombre,string email,string password,Cargo cargo);
    Cargo getCargo(); 
    ~DTEmpleado();
};





#endif