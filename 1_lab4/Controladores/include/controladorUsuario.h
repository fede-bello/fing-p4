#ifndef CONTU
#define CONTU

#include "../../Clases/include/Empleado.h"
#include "controladorHostal.h"
class controladorUsuario{
    private:
        static controladorUsuario * instance;
        controladorUsuario();
        vector<string> ArregloEmail;
        map<string,Empleado*> MapaEmpleado;
        map<string,Huesped*> MapaHuesped;

    public:
        static controladorUsuario * getInstance(); 
        Hostal find(string nombre);

        //hechas por diego
        vector<string> getEmail();
        void setEmail(string EmailGuardado);
        void liberar();
        ~controladorUsuario();
        //Alta Usuario
        DTEmpleado* NuevoEmpleado(string email,string password,string nombre,CargoEmp cargo);
        DTHuesped* NuevoHuesped(string email,string password,string nombre, bool esFinger);
        void ActualizarMail(DTUsuario *usuario,string mail);
        void CancelarUsuario(DTUsuario *usuario);
        void ConfimarAltaEmpleado(DTEmpleado *empleado);
        void ConfimarAltaHuesped(DTHuesped *huesped);
        //FIN Alta Usuario
        //Alta Hostal
        //Alta de Habitacion
        //Asignar Empleado a Hostal
        vector<DTEmpleado> obtenerEmpleadoHostal();
        void ActualizarCargo(string nombre,CargoEmp cargo);
        void AsignarEmpleado();
        //Realizar Reserva
        vector<DTHuesped> obtenerHuespedes();
        DTHuesped elegirHuesped(string Mail);
        void confirmarAltaReservaIndividual();
        void confirmarAltaReservaGrupal();
        void cancelarReserva();
        //Consultar top 3 de hostales
        //Registrar Estadia
        //Finalizar Estadia
        //Calificar Estadia
        //Comentar Calificacion
        //Consulta de Usuario
        //Consulta de Hostal
        //Consulta de Reserva
        //Consulta de Estadia
        //Baja de Reserva

};

#endif
