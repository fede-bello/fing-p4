#ifndef HOS
#define HOS

#include "../../DataType/include/DTHostal.h"
#include "Habitacion.h"
class Hostal
{
private:
    string nombre;
    string direccion;
    int telefono;
public:
    Hostal(string nombre,string direccion,int telefono);
    string getNombre();
    string getDireccion();
    int getTelefono();
    DTHostal getDTHostal();
    ~Hostal();
};


#endif