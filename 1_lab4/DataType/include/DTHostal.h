#ifndef DTHOS
#define DTHOS


#include "DTHabitacion.h"





class DTHostal{
    private:
        //Falta pseudo atributo para DTHabitacion
        string Nombre;
        string Direccion;
        string Telefono;
    public:
        DTHostal();
        DTHostal(string Nombre,string Direccion,string Telefono);
        string getNombre();
        string getDireccion();
        string getTelefono();
        void imprimir();
        ~DTHostal();
  };





#endif
