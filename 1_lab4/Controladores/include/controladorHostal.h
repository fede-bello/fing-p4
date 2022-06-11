#ifndef CONTH
#define CONTH

#include"../../Clases/include/Hostal.h"
#include"controladorReserva.h"

class ControladorHostal {
private:
    static ControladorHostal * instancia;
    ControladorHostal();
    map<string,Hostal> MapaHostal;
    
public:
    static ControladorHostal * getInstance();
    void operacion();
    ~ControladorHostal();
};


#endif