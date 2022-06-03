#ifndef DTUS
#define DTUS


#include "DTHabitacion.h"
class DTUsuario{
private:
    string name;
    string email;
    string password;
public:
    DTUsuario(string nombre,string direccion,string password);
    virtual ~DTUsuario();
};





#endif