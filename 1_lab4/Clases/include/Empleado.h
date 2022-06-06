#ifndef EMPL
#define EMPL

#include "Hostal.h"
#include "../../DataType/include/DTEmpleado.h"

class Empleado: public Usuario{
    private:
        CargoEmp Cargo;
        Hostal *hos;

    public:
        //Constructoras
        Empleado();
        Empleado(string Nombre, string Password, string Mail, CargoEmp Cargo);
        //Setters y getters
        CargoEmp getCargo();
        Hostal* getHostal();
        void setCargo(CargoEmp Cargo);
        void setHostal(Hostal *hos);
        //Operaciones
        bool empleadoAsignadoAHostal();
        //asignarHostal es lo mismo que setHostal

        //Destructora
        ~Empleado();
    
};


#endif