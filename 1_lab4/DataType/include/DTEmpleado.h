#ifndef DTUSE
#define DTUSE

#include "DTUsuario.h"

enum Cargo{
    Limpieza, Administracion, Infrasetructura, Recepcion
};

class Empleado: public Usuario{
    private:
        CargoEmp Cargo;
        //Esto no se si va, no se si los DT tienen cosas asociadas
        /* Hostal *hos; */

    public:
        //Constructoras
        DTEmpleado();
        DTEmpleado(string Nombre, string Password, string Mail, CargoEmp Cargo);
        //Setters y getters
        CargoEmp getCargo();
        /*Hostal* getHostal();   LO MISMO QUE ARRIBA, NO SE SI VA*/
        
        //Destructora
        ~DTEmpleado();
    
};


#endif