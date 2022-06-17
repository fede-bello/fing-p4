#ifndef IUSUARIO
#define IUSUARIO

#include "../../Clases/include/Empleado.h"
#include "../../Controladores/include/controladorHostal.h"

class IcontroladorUsuario{
    public:
        //virtual static controladorUsuario * getInstance(); 
        virtual map<string,Empleado*> getEmpleados();
        virtual map<string,Huesped*> getHuesped(); 
        virtual Hostal find(string nombre) = 0;
        virtual vector<string> getEmail()  = 0;
        virtual void setEmail(string EmailGuardado)  = 0;
        virtual void liberar()  = 0;
        virtual~IcontroladorUsuario(){};
        //Alta Usuario
        virtual DTEmpleado* NuevoEmpleado(string email,string password,string nombre,CargoEmp cargo)  = 0;
        virtual DTHuesped* NuevoHuesped(string email,string password,string nombre, bool esFinger) = 0;
        virtual void ActualizarMail(DTUsuario *usuario,string mail) = 0;
        virtual void CancelarUsuario(DTUsuario *usuario) = 0;
        virtual void ConfimarAltaEmpleado(DTEmpleado *empleado) = 0;
        virtual void ConfimarAltaHuesped(DTHuesped *huesped) = 0;
        //FIN Alta Usuario
        //Alta Hostal
        //Alta de Habitacion
        //Asignar Empleado a Hostal
        virtual vector<DTEmpleado> obtenerEmpleadoHostal() = 0;
        virtual void ActualizarCargo(string nombre,CargoEmp cargo) = 0;
        virtual void AsignarEmpleado() = 0;
        //Realizar Reserva
        virtual vector<DTHuesped> obtenerHuespedes() = 0;
        virtual DTHuesped elegirHuesped(string Mail) = 0;
        virtual void confirmarAltaReservaIndividual() = 0;
        virtual void confirmarAltaReservaGrupal() = 0;
        virtual void cancelarReserva() = 0;
        //Consultar top 3 de hostales
        //Registrar Estadia
        //Finalizar Estadia
        //Calificar Estadia
        virtual void calificarEstadia(int codigo, int calif, string texto) = 0;
        //Comentar Calificacion
        //Consulta de Usuario
        virtual vector<DTEmpleado> obtenerEmpleados() = 0;
        virtual DTUsuario elegirUsuario(string email) = 0;
        virtual void informacionUsuario(DTUsuario usuarioInfo) = 0;
        //Consulta de Hostal
        //Consulta de Reserva
        //Consulta de Estadia
        //Baja de Reserva
};

#endif