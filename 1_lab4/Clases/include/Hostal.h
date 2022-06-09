#ifndef HOS
#define HOS

#include<string>
#include "Habitacion.h"
#include "../../DataType/include/DTHostal.h"
#include "../../DataType/include/DTHabitacion.h"

class Hostal{
private:
    string Nombre;
    string Direccion;
    int Telefono;
    Habitacion *hab; // deberia ser una coleccion
public:
    Hostal();
    Hostal(string Nombre,string Direccion,int Telefono);
    string getNombre();
    string getDireccion();
    int getTelefono();
    void setNombre(string nombre);
    void setDireccion(string direccion);
    void setTelefono(int telefono);
    void setHabitacion(Habitacion *hab);
    //Operaciones
    DTHostal getDTHostal();
    //DTHabitacion* getHabitacion();//falta info para hacerla
    DTHabitacion infHab(int cres);

    void eliminarLinkReserva();//falta decir a que reserva hago referencia, no hay forma de accder a reserva desde hostal

    //Destructoras
    ~Hostal();
};


#endif   


