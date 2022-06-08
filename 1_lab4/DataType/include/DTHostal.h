#ifndef DTHOS
#define DTHOS

#include<iostream>
#include<string>
#include "DTHabitacion.h"
#include "DTHabitacion.h"

class DTHostal{
    private:
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
