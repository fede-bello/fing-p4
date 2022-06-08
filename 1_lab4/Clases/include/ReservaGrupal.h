#ifndef RESG
#define RESG

#include "Reserva.h"
#include "Huesped.h"
#include "../../DataType/include/DTReservaGrupal.h"
#include "../../DataType/include/DTFecha.h"

class ReservaGrupal: public Reserva{ 
    private:
        int Cantidad;
        Huesped** huespedes;
    public:
        //constructor
        ReservaGrupal();
        ReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int cantidad,Huesped **Arreglo);
        //set y get
        int getCantidad();
        void setCantidad(int cantidad);
        //destructor
        ~ReservaGrupal();
        //operaciones
        Huesped** getHuespedes();
        void setHuespedes(Huesped** arreglo_huespedes);       
        virtual float calcularCosto();
};

#endif