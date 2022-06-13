#ifndef USH
#define USH


#include "Usuario.h"
#include"../../DataType/include/DTHuesped.h"




class Huesped:public Usuario{
    private: 
        bool esFinger;
    public:
        Huesped();
        Huesped(string nombre, string password, string email, bool esFinger);
        bool getEsFinger();
        void setEsFinger(bool finger);
        DTHuesped getDTHuesped();
        bool mismoMail(string email);
        //asociarHues()?????
        ~Huesped();
};

#endif
