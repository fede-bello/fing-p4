#ifndef HOS
#define HOS

#include "../../DataType/include/DTHostal.h"
#include "Habitacion.h"
class Hostal
{
private:
    string Nombre;
    string Direccion;
    int Telefono;
public:
    Hostal();
    Hostal(string Nombre,string Direccion,int Telefono);
    void setNombre(string nombre);
    void setDireccion(string direccion);
    void setTelefono(int telefono);
    string getNombre();
    string getDireccion();
    int getTelefono();
    DTHostal getDTHostal();
    ~Hostal();
};


#endif