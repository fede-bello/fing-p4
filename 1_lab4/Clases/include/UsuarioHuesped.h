#ifndef USH
#define USH

#include <iostream>
#include<string>
#include"../../DataType/include/DTUsuarioHuesped.h"


class Huesped{
    private: 
        string nombre, email;
        bool esFinger;
    public:
        Huesped();
        Huesped(string nombre, string email, bool esFinger);
        void setNombre(string nombre);
        string getNombre();
        void setEmail(string email);
        string getEmail();
        void setEsFinger(bool esFinger);
       
        bool getEsfinger();
        ~Huesped();
};

#endif
