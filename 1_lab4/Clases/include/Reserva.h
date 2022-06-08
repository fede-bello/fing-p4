#ifndef RES
#define RES

#include "Estadia.h"
#include "Huesped.h"
#include "../../DataType/include/DTReservaIndividual.h"
#include "../../DataType/include/DTReservaGrupal.h"

class Reserva{
    protected:
        int codigo;
        DTFecha checkIn,checkOut;
        EstadoReserva estado;
        Huesped *hues;
        Estadia *est;
    public:
        //constructores
        Reserva();
        Reserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int cantidad);
        //destructor
        ~Reserva();
        //operaciones
        //virtual float calcularCosto();
        int getCodigo();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        EstadoReserva getEstado();     
        Estadia* getEstadia();
        Huesped* getHuesped();
        void setCodigo(int codigo);
        void setCheckIn(DTFecha checkIn);
        void setCheckOut(DTFecha checkOut);
        void setEstado(EstadoReserva estado);
        void setEstadia(Estadia *estadia);
        void setHuesped(Huesped *huesped);
};



#endif