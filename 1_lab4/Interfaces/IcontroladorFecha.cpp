#include "../Controladores/include/controladorFecha.h"
class IcontroladorFecha{
    public:
        virtual static IcontroladorFecha * getInstance();
        virtual void ModificarFechaActual(DTFecha nueva);
        virtual DTFecha getFechaActual();
        virtual void operacion();
        virtual ~controladorFecha();

}