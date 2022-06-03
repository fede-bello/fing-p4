#ifndef DTUSH
#define DTUSH

#include<iostream>
#include<string>

using namespace std;

class DTHuesped{
    private:
        string nombre, email;
        bool esFinger;
    public:
        DTHuesped();
        DTHuesped(string nombre, string email, bool esFinger);
        string getNombre();
        string getEmail();
        bool operator==(DTHuesped &otro) const;
        bool getEsFinger();
        ~DTHuesped();
};

inline ostream &operator<< (ostream& o, DTHuesped * hues){
	if (hues->getEsFinger())
		return o<<"Nombre: "<< hues->getNombre()<<endl<< "Email: "<<hues->getEmail()<<endl<< "Finger: Si"<<endl;
	else
		return o<<"Nombre: "<< hues->getNombre()<<endl<< "Email: "<<hues->getEmail()<<endl <<"Finger: No"<<endl;
}

#endif


