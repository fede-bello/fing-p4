#ifndef RESG
#define RESG

#include "Reserva.h"
#include "Huesped.h"
#include "../../DataType/include/DTReservaGrupal.h"
#include "../../DataType/include/DTFecha.h"

class ReservaGrupal: public Reserva{ 
    private:
        int Cantidad;
        map<string,Huesped*> huespedes; //esto creo que hay que modelarlo como un map
    public:
        //constructor
        ReservaGrupal();
        ReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int cantidad);
        //set y get
        int getCantidad();
        void setCantidad(int cantidad);
        //destructor
        ~ReservaGrupal();
        //operaciones
        map<string,Huesped*> getHuespedes();
        void setHuespedes(map<string,Huesped*> huespedes);       
        //virtual float calcularCosto();
};

#endif