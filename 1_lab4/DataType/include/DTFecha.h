#ifndef DTFE
#define DTFE

#include<iostream>
#include<string>
#define MAX_HABITACIONES 20
#define MAX_RESERVAS 20
#define MAX_HUESPEDES 50 
using namespace std;

class DTFecha{
    private: 
        int dia,mes,anio,hora;
    public:

        //Constructoras
        DTFecha();
        DTFecha(int d, int m, int a,int h);
        //getters
        int getDia(); 
        int getMes();
        int getAnio();
        int getHora();
        // bool operator>=(const DTFecha &otro) const;
        // bool operator<=(const DTFecha &otro) const;
        DTFecha avanzarFecha(int i); //avanza fecha i dias, no se si la necesitaremos
        DTFecha retrocederFecha(int i); //retrocede fecha i dias, no se si la necesitaremos
        int diferenciasFechas(DTFecha f); //devuelve la cantidad de dias de diferencia entre dos fechas
        bool operator==(const DTFecha &otro) const;
        //Destructora
        ~DTFecha();
};
#endif