
#ifndef DTRES
#define DTRES

#include "DTEstadia.h"//
#include "DTHuesped.h"//
#include "DTFecha.h"

enum EstadoReserva {
    Abierta, Cerrada, cancelada  
};



class DTReserva{
    protected: 
        //Falta pseudo atributo para DTHuesped y DTEstadia
        int Codigo;
        DTFecha CheckIn, CheckOut;
        EstadoReserva Estado;
        float Costo;
        
    public:
        //constructores
        DTReserva();
        DTReserva(int Codigo , DTFecha CheckIn, DTFecha CheckOut, EstadoReserva estado, float Costo);
        //geters y seters
        int getCodigo();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        EstadoReserva getEstado();
        float getCosto();
        bool operator==(const DTReserva &otro) const;
        void aumentarCantidad();
        void imprimir();
        virtual ~DTReserva();
};


#endif



