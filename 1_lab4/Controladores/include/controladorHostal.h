#ifndef CONTH
#define CONTH

#include"../../Clases/include/Hostal.h"
#include"controladorReserva.h"

class ControladorHostal {
private:
    static ControladorHostal * instancia;
    ControladorHostal();
    DTHostal *HostalActual=NULL;
    
public:
    static ControladorHostal * getInstance();
    void operacion();
    ~ControladorHostal();
};


#endif