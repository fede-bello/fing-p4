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
        map<string,Huesped> MapaHuesped;

    public:
        static controladorUsuario * getInstance();
        //hechas por diego 
        vector<string> getEmail();
        void setEmail(string EmailGuardado);
        void liberar();
        ~controladorUsuario();
        //Alta Usuario
        DTEmpleado* NuevoEmpleado(string email,string password,string nombre,CargoEmp cargo);
        DTHuesped* NuevoHuesped(string email,string password,string nombre, bool esFinger);
        void ActualizarMail(DTUsuario *usuario,string mail);
        void CancelarUsuario(DTUsuario *usuario);
        void ConfimarAltaEmpleado(DTEmpleado *empleado);
        void ConfimarAltaHuesped(DTHuesped *huesped);
        //Alta Usuario
        //fin hechos por diego

};

#endif
