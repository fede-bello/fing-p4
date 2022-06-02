
#ifndef DTR
#define DTR

#include"DTFecha.h"
#include"DTHuesped.h"
#include"DTHabitacion.h"




enum EstadoReserva {
    Abierta, Cerrada, Cancelada   
};

class DTReserva{
    protected: 
        int codigo;
        DTFecha checkIn, checkOut;
        EstadoReserva estado;
        float costo;
        int habitacion;
        int cantidad;
    public:
        //constructores
        DTReserva();
        DTReserva(int habitacion , DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo , int codigo, int cantidad);
        //geters y seters
        int getCodigo();
        float getCosto();
        int getHabitacion();
        int getCantidad();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        EstadoReserva getEstado();
        bool operator==(const DTReserva &otro) const;
        void aumentarCantidad();
        virtual int cast(); //operacion fantasma que define el polimorfismo para poder usar dynamic_cast en registrarReserva
        //destructor
        ~DTReserva();
};


#endif



