#ifndef EMPL
#define EMPL

#include "Hostal.h"
#include "Calificacion.h"
#include "Usuario.h"
#include "../../DataType/include/DTEmpleado.h"





class Empleado: public Usuario{
    private:
        CargoEmp Cargo;
        Hostal *hos;
        Calificacion *calif;

    public:
        //Constructoras
        Empleado();
        Empleado(string Nombre, string Password, string Mail, CargoEmp Cargo);
        //Setters y getters
        CargoEmp getCargo();
        Hostal* getHostal();
        Calificacion* getCalificacion();
        void setCargo(CargoEmp Cargo);
        void setHostal(Hostal *hos);
        void setCalificacion(Calificacion *calif);
        //Operaciones
        bool empleadoAsignadoAHostal();
        //asignarHostal es lo mismo que setHostal
        DTEmpleado getDTEmpleado();
        bool mismoMail(string email);

        //Destructora
        ~Empleado();
    
};


#endif