#ifndef USH
#define USH

#include <iostream>
#include<string>
#include"../../DataType/include/DTHuesped.h"


class Huesped:public Usuario{
    private: 
        bool esFinger;
    public:
        Huesped();
        Huesped(string nombre, string password, string email, bool esFinger);
        bool getEsfinger();
        void setEsFinger(bool finger);
        ~Huesped();
};

#endif
