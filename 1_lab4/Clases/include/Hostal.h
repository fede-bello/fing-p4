#ifndef HOS
#define HOS

#include "Habitacion.h"
#include "../../DataType/include/DTHostal.h"

class Hostal{
private:
    string Nombre;
    string Direccion;
    int Telefono;
    Habitacion *hab;
public:
    Hostal();
    Hostal(string Nombre,string Direccion,int Telefono);
    string getNombre();
    string getDireccion();
    int getTelefono();
    DTHostal getDTHostal();
    Habitacion* getHabitacion();
    void setNombre(string nombre);
    void setDireccion(string direccion);
    void setTelefono(int telefono);
    void setHabitacion(Habitacion *hab);
    ~Hostal();
};


#endif   