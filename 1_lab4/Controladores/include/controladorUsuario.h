#ifndef CONTU
#define CONTU

#include "../../Clases/include/Empleado.h"
#include "controladorHostal.h"
class controladorUsuario{
    private:
        static controladorUsuario * instance;
        controladorUsuario();
        //seria Mucho mas conveniente tener estos antes de un Empleado y un Huesped
        vector<string>ArregloEmail;
        map<string,Empleado> MapaEmpleado;
        map<string,Huesped> MapaUsuario;

    public:
        static controladorUsuario * getInstance();
        //hechas por diego 
        vector<string> getEmail();
        void setEmail(string EmailGuardado);
        void setPassword(string PasswordGuardado);
        void setNombre(string NombreGuardado);
        void setCargoEmp(CargoEmp CargoEmpGuardado);
        void setEsFinger(bool EsFingerGuardado);
        void liberar();
        ~controladorUsuario();
        //fin hechos por diego

};

#endif
