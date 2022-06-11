#ifndef CONTU
#define CONTU

#include "../../Clases/include/Usuario.h"
#include "controladorHostal.h"
class controladorUsuario{
    private:
        static controladorUsuario * instance;
        controladorUsuario();
        string EmailGuardado,PasswordGuardado, NombreGuardado;
        CargoEmp CargoEmpGuardado;
        bool EsFingerGuardado;
        vector<string>ArregloEmail;
        map<string,Usuario> MapaUsuario;

    public:
        static controladorUsuario * getInstance();
        //hechas por diego 
        vector<string> getEmail();
        string getPassword();
        string getNombre();
        CargoEmp getCargoEmp();
        bool getEsFinger();
        void setEmail(string EmailGuardado);
        void setPassword(string PasswordGuardado);
        void setNombre(string NombreGuardado);
        void setCargoEmp(CargoEmp CargoEmpGuardado);
        void setEsFinger(bool EsFingerGuardado);
        ~controladorUsuario();
        //fin hechos por diego

};

#endif
