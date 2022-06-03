#ifndef DTHOS
#define DTHOS


#include "DTHabitacion.h"
class DTHostal
{
private:
    string nombre;
    string direccion;
    int telefono;
public:
    DTHostal(string nombre,string direccion,int telefono);
    string getNombre();
    string getDireccion();
    int getTelefono();
    ~DTHostal();
};





#endif