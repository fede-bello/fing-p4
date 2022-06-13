#ifndef DTHOS
#define DTHOS


#include "DTHabitacion.h"





class DTHostal{
    private:
        //Falta pseudo atributo para DTHabitacion
        string Nombre;
        string Direccion;
        int Telefono;
    public:
        DTHostal();
        DTHostal(string Nombre,string Direccion,int Telefono);
        string getNombre();
        string getDireccion();
        int getTelefono();
        ~DTHostal();
  };





#endif
