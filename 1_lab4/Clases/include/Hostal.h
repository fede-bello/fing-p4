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
        map<int, Habitacion> mapaHabitaciones; //mapaHabitaciones es un map (diccionario) de Habitacion
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
        DTHostal getDTHostal();//✅
        DTReserva darReservasHuespedHos();//FALTA
        Reserva getReservasHostal();//FALTA
        vector<DTHabitacion> darInfoHabs();//✅
        DTReserva darReservasHostal();
        int darNumHab(Reserva nr);//✅
        DTHuesped huespedes(Reserva nr);//FALTA
        DTHabitacion infoHab(int cres);//✅
        void eliminarLinkReserva(int cres);//✅agregue a que reserva hace referencia
        void AsociarReservaHostal(int r,int habitacion);//✅
        //Destructoras
        ~Hostal();
};


#endif   


