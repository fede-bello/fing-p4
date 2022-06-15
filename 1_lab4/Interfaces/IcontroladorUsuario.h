#include "../Controladores/include/controladorUsuario.h"

class IcontroladorUsuario{
    public:
        //virtual static controladorUsuario * getInstance(); 
        virtual Hostal find(string nombre);

        //hechas por diego
        virtual vector<string> getEmail();
        virtual void setEmail(string EmailGuardado);
        virtual void liberar();
        virtual ~IcontroladorUsuario();
        //Alta Usuario
        virtual DTEmpleado* NuevoEmpleado(string email,string password,string nombre,CargoEmp cargo);
        virtual DTHuesped* NuevoHuesped(string email,string password,string nombre, bool esFinger);
        virtual void ActualizarMail(DTUsuario *usuario,string mail);
        virtual void CancelarUsuario(DTUsuario *usuario);
        virtual void ConfimarAltaEmpleado(DTEmpleado *empleado);
        virtual void ConfimarAltaHuesped(DTHuesped *huesped);
        //FIN Alta Usuario
        //Alta Hostal
        //Alta de Habitacion
        //Asignar Empleado a Hostal
        virtual vector<DTEmpleado> obtenerEmpleadoHostal();
        virtual void ActualizarCargo(string nombre,CargoEmp cargo);
        virtual void AsignarEmpleado();
        //Realizar Reserva
        virtual vector<DTHuesped> obtenerHuespedes();
        virtual DTHuesped elegirHuesped(string Mail);
        virtual void confirmarAltaReservaIndividual();
        virtual void confirmarAltaReservaGrupal();
        virtual void cancelarReserva();
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