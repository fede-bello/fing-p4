#ifndef DTHABITACION
#define DTHABITACION

#include<iostream>
#include<string>
#include"DTFecha.h"

using namespace std;


class DTHabitacion{
    private:
        int numero=-100, capacidad=-100;
        float precio=-100;
    public:
        DTHabitacion();
        DTHabitacion(int numero, int capacidad, float precio);
        int getNum();
        int getCap();
        float getPrecio();
        bool operator==(const DTHabitacion &otro) const;
        ~DTHabitacion();
};

inline ostream &operator<< (ostream& o, DTHabitacion * hab){
	return o<<"Número habitación: "<< hab->getNum()<<endl<< "Capacidad habitación: " << hab->getCap() <<endl<< "Costo: $"<<hab->getPrecio()<<endl;
}

#endif


