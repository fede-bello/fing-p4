#ifndef HOS
#define HOS


#include "Habitacion.h"
#include "../../DataType/include/DTHostal.h"
#include "../../DataType/include/DTHabitacion.h"

class Hostal{
    private:
        string Nombre;
        string Direccion;
        int Telefono;
        map<int, Habitacion> MapaHabitaciones; //habitaciones es un map (diccionario) de Habitacion
    public:
        Hostal();
        Hostal(string Nombre,string Direccion,int Telefono);
        string getNombre();
        string getDireccion();
        int getTelefono();
        void setNombre(string nombre);
        void setDireccion(string direccion);
        void setTelefono(int telefono);
        void agregarHabitacionAHostal(DTHabitacion hab);
        //Operaciones
        DTHostal getDTHostal();
        DTReserva darReservasHuespedHos();
        Reserva getReservasHostal();//No se como crear un conjunto de reservas desde hostal
        DTHabitacion* darInfoHabs();
        DTReserva darReservasHostal();
        int darNumHab(Reserva nr);
        DTHuesped huespedes(Reserva nr);
        DTHabitacion infoHab(int cres);//FALTA
        void eliminarLinkReserva();//falta decir a que reserva hago referencia, no hay forma de acceder a reserva desde hostal
        void AsociarReservaHostal(int r,int habitacion );//FALTA
        //Destructoras
        ~Hostal();
};


#endif   


