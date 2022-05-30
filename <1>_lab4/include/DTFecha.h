#ifndef DTFECHA
#define DTFECHA

#include<iostream>
#include<string>
#define MAX_HABITACIONES 10
#define MAX_RESERVAS 15
#define MAX_HUESPEDES 50 

class DTFecha{
    private: 
        int dia,mes,anio;
    public:
        DTFecha();
        DTFecha(int d, int m, int a);
        int getDia(); 
        int getMes();
        int getAnio();
        // bool operator>=(const DTFecha &otro) const;
        // bool operator<=(const DTFecha &otro) const;
        DTFecha avanzarFecha(int i); //avanza fecha i dias, no se si la necesitaremos
        DTFecha retrocederFecha(int i); //retrocede fecha i dias, no se si la necesitaremos
        int diferenciasFechas(DTFecha f); //devuelve la cantidad de dias de diferencia entre dos fechas
        bool operator==(const DTFecha &otro) const;
        ~DTFecha();
};
#endif