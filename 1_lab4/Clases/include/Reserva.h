#ifndef RES
#define RES

#include "Habitacion.h"
#include "Huesped.h"
#include "../../DataType/include/DTReservaIndividual.h"
#include "../../DataType/include/DTReservaGrupal.h"

class Reserva{
    protected:
        int codigo;
        DTFecha checkIn,checkOut;
        EstadoReserva estado;
        Habitacion *hab;
        Huesped *hues;
    public:
        //constructores
        Reserva();
        Reserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int cantidad);
        //destructor
        ~Reserva();
        //operaciones
        void aumentarCantidad();
        virtual float calcularCosto();
        int getCodigo();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        EstadoReserva getEstado();     
        Habitacion* getHabitacion();
        Huesped* getHuesped();
        void setCodigo(int codigo);
        void setCheckIn(DTFecha checkIn);
        void setCheckOut(DTFecha checkOut);
        void setEstado(EstadoReserva estado);
        void setHabitacion(Habitacion *habitacion);
        void setHuesped(Huesped *huesped);
};



#endif