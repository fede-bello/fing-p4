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
        string *ArregloEmail;
        Usuario **ArregloUsuario;
    public:
        static controladorUsuario * getInstance();
        int indEmail=0;
        int indUsuario=0;
        //hechas por diego 
        string* getEmail();
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

};

#endif
