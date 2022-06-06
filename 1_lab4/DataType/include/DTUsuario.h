#ifndef DTUS
#define DTUS
using namespace std;
#include "DTHabitacion.h"
class DTUsuario{
private:
    string nombre;
    string email;
    string contra;
public:
    DTUsuario(string nombre,string email,string contra);
    string getNombre();
    string getEmail();
    string getContra();
    virtual ~DTUsuario();
};





#endif