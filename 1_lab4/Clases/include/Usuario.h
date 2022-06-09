#ifndef US
#define US


#include "../../DataType/include/DTUsuario.h"

class Usuario{
    protected:
        string Nombre, Password, Mail;

    public:
        //Constructoras 
        Usuario();
        Usuario(string Nombre, string Password, string Mail);

        //Setters y getters
        string getNombre();
        string getPassword();
        string getMail();
        void setNombre(string Nombre);
        void setPassword(string Password);
        void setMail(string Mail);

        //Destructora
        virtual ~Usuario();
};









#endif