#ifndef CONTU
#define CONTU

#include "../../Interfaces/include/IcontroladorUsuario.h"

class controladorUsuario : public IcontroladorUsuario{
    private:
        static controladorUsuario * instance;
        controladorUsuario();
        vector<string> ArregloEmail;
        map<string,Empleado*> MapaEmpleado;
        map<string,Huesped*> MapaHuesped;
    public:
        static controladorUsuario * getInstance();
        map<string,Empleado*> getEmpleados();
        map<string,Huesped*> getHuespedes(); 
        Hostal find(string nombre); //FALTA
        vector<string> getEmail();
        ~controladorUsuario();
        void setEmail(string EmailGuardado);
        void liberar();
        //Alta Usuario
        DTEmpleado* NuevoEmpleado(string email,string password,string nombre,CargoEmp cargo);
        DTHuesped* NuevoHuesped(string email,string password,string nombre, bool esFinger);
        void ActualizarMail(DTUsuario *usuario,string mail);
        void CancelarUsuario(DTUsuario *usuario);
        void ConfirmarAltaEmpleado(DTEmpleado *empleado);
        void ConfirmarAltaHuesped(DTHuesped *huesped);
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
        void calificarEstadia(int codigo, int calif, string texto);
        //Comentar Calificacion
        vector<DTCalificacion> calificacionesSinResponder(string mail);
        //Consulta de Usuario
        vector<DTEmpleado> obtenerEmpleados();
        DTUsuario elegirUsuario(string email);
        void informacionUsuario(DTUsuario usuarioInfo);
        //Consulta de Hostal
        //Consulta de Reserva
        //Consulta de Estadia
        //Baja de Reserva

};

#endif
