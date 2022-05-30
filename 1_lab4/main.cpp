
#include "./include/Sistema.h"

using namespace std;
using namespace std::string_literals;

int main()
{
	Sistema sistema;
	int numero = 1, cantHuespedes = 0, cantHabitaciones = 0, cantReservas = 0, codigo = 1000;
	cout << "Bienvenido " << endl<< endl;
	while (numero < 7 && numero > 0)
	{
		{ // opciones
			cout << "Por favor digite el numero que le corresponda" << endl
				 << endl;
			cout << "1. Agregar Huesped" << endl;
			cout << "2. Agregar Habitación" << endl;
			cout << "3. Obtener Huéspedes" << endl;
			cout << "4. Obtener Habitaciones" << endl;
			cout << "5. Registrar Reserva" << endl;
			cout << "6. Obtener Reservas" << endl;
			cout << "7. Salir" << endl;
			cin >> numero;
		}
		switch (numero){ // inicio switch
		case 1:{ // inicio Agendar Huesped
			bool salir = false;
			while (!salir){
				cout << "Ha digitado la opcion de Agregar Huesped" << endl;
				try{
					cout << "Por favor escriba su email " << endl;
					string email;
					cin >> email;
					for (int i = 0; i < sistema.indHuesped; i++){
						if (email == sistema.ArrHuesped[i]->getEmail())
							throw "std::invalid_argument"; //("Ya existe un huesped con el mismo mail")
					}
					{ // Nuevo Usuario
						string nombre;
						bool esFinger;
						int finger;
						cout << "Por favor escriba su nombre " << endl;
						cin.ignore();
						getline(cin, nombre);
						cout << "Presiona 1 si perteneces a la facultad de Ingenieria, otro numero si no" << endl;
						cin >> finger;
						if (finger == 1)
							esFinger = true;
						else
							esFinger = false;
						sistema.agregarHuesped(nombre, email, esFinger);
						salir = true;
					} // Fin Nuevo Usuario
				}
				catch (...)
				{
					cout << "std::invalid_argument" << endl;
					cout << "Ya existe un huesped con el mismo mail" << endl;
					cout << endl;
				}
			}
		} // Fin Agendar Huesped
		break;
		case 2:{ // Inicio Agregar Habitacion
			bool salir = false;
			while (!salir){
				cout << "Ha digitado la opcion de Agregar Habitación" << endl;
				try{
					cout << "Por favor digite el numero de su habitacion" << endl;
					int numero;
					cin >> numero;
					for (int i = 0; i < sistema.indHabitacion; i++)
					{
						if (numero == sistema.ArrHabitacion[i]->getNum())
							throw "std::invalid_argument"; //("Ya existe una habitacion con el mismo numero")
					}
					// Fin Habitacion Ya Registrada
					{
						int capacidad;
						float precio;
						cout << "Ingresa la capacidad de la habitacion" << endl;
						cin >> capacidad;
						cout << "Ingresa el precio de la habitacion" << endl;
						cin >> precio;
						sistema.agregarHabitacion(numero, capacidad, precio);
						salir = true;
					}
				}
				catch (...)
				{
					cout << "std::invalid_argument" << endl;
					cout << "Ya existe una habitacion con el mismo numero" << endl;
					cout << endl;
				}
			}
		} // Fin Agregar Habitacion
		break;
		case 3:{ // Inicio Obtener Huespedes
			cout << "Ha digitado la opcion de Obtener Huéspedes" << endl;
			if (sistema.indHuesped == 0){
				cout << "No hay huespedes registrados hasta el momento" << endl;
				break;
			}
			DTHuesped **ArrHuesped = sistema.obtenerHuespedes(cantHuespedes);
			int i = 0;
			while (i < cantHuespedes){
				cout << "Huesped ";
				cout << i+1;
				cout << ": " << endl;
				cout << ArrHuesped[i] << endl;
				delete ArrHuesped[i];
				i++;
			}
			delete[] ArrHuesped;
		} // Fin Obtener Huespedes
		break;
		case 4:
		{ // Inicio Obtener Habitaciones
			cout << "Ha digitado la opcion de Obtener Habitaciones" << endl;
			if (sistema.indHabitacion == 0)
			{
				cout << "No hay habitaciones registradas hasta el momento" << endl;
				break;
			}
			DTHabitacion **ArrHabitacion = sistema.obtenerHabitaciones(cantHabitaciones);
			int i = 0;
			while (i < cantHabitaciones)
			{
				cout << "Habitacion ";
				cout << i+1;
				cout << ": " << endl;
				cout << ArrHabitacion[i] << endl;
				delete ArrHabitacion[i];
				i++;
				
			}
			delete[] ArrHabitacion;
		} // Fin Obtener Habitaciones
		break;
		case 5:	{ // Inicio Registrar Reservas
			{// Inicio Caso no hay habitacion o huespedes
				cout << "Ha digitado la opcion de Registrar Reserva" << endl;
				try{
					if (sistema.indHuesped == 0)
						throw "std::invalid_argument";
				}
				catch (...){
					cout << "std::invalid_argument" << endl;
					cout << "Disculpe,no hay usuarios que puedan realizar la reserva, pruebe mas tarde" << endl;
					break;
				}
				try{
					if (sistema.indHabitacion == 0)
						throw "std::invalid_argument";
				}
				catch (...){
					cout << "std::invalid_argument" << endl;
					cout << "No hay habitaciones disponibles, pruebe mas tarde" << endl;
					break;
				}
			}// Fin no hay habitaciones o Huespedes
			
			bool salir = false;
			bool encontre = false;
			int num_habitacion;
			float precio_habitacion;
			while (!salir){ // Verficacion Habitacion
				try{
					cout << "Por favor digite el numero de su habitacion" << endl;
					int i = 0;
					cin >> num_habitacion;
					while (!encontre && i < sistema.indHabitacion){
						if (num_habitacion == sistema.ArrHabitacion[i]->getNum())
							encontre = true;
						precio_habitacion = sistema.ArrHabitacion[i]->getPrecio();
						i++;
					}
					if (!encontre)
						throw "std::invalid_argument";
					else
						salir = true;
				}
				catch (...){
					cout << "std::invalid_argument" << endl;
					cout << "La Habitacion ingresada no fue encontrada, intente denuevo" << endl;
				}
			}
			int cantidad;
			cout << "Ingrese la cantidad de huespedes de su reserva" << endl;
			cin >> cantidad;
			int diaCheckIn;
			int mesCheckIn;
			int anioCheckIn;
			int diaCheckOut;
			int mesCheckOut;
			int anioCheckOut;
			salir = false;
			while (!salir){
				try
				{
					cout << "Ingrese el dia del checkIn:" << endl;
					cin >> diaCheckIn;
					if (diaCheckIn < 1 || diaCheckIn > 31)
						throw 1;
					salir = true;
				}
				catch (...)
				{
					cout << "std::invalid_argument" << endl;
					cout << "Ingrese un dia entre 1 y 31" << endl;
				}
			}
			salir = false;
			while (!salir){
				try
				{
					cout << "Ingrese el mes del checkIn:" << endl;
					cin >> mesCheckIn;
					if (mesCheckIn < 1 || mesCheckIn > 12)
						throw 2;
					salir = true;
				}
				catch (...)
				{
					cout << "std::invalid_argument" << endl;
					cout << "Ingrese un mes entre 1 y 12" << endl;
					cout << endl;
				}
			}
			salir = false;
			while (!salir){
				try
				{
					cout << "Ingrese el año del checkIn:" << endl;
					cin >> anioCheckIn;
					if (anioCheckIn < 1900)
						throw 3;
					salir = true;
				}
				catch (...)
				{
					cout << "std::invalid_argument" << endl;
					cout << "Ingrese un año mayor a 1900" << endl;
					cout << endl;
				}
			}
			salir = false;
			while (!salir){
				try
				{
					cout << "Ingrese el dia del checkOut:" << endl;
					cin >> diaCheckOut;
					if (diaCheckOut < 1 || diaCheckOut > 31)
						throw 4;
					salir = true;
				}
				catch (...)
				{
					cout << "std::invalid_argument" << endl;
					cout << "Ingrese un dia entre 1 y 31" << endl;
					cout << endl;
				}
			}
			salir = false;
			while (!salir){
				try
				{
					cout << "Ingrese el mes del checkOut:" << endl;
					cin >> mesCheckOut;
					if (mesCheckOut < 1 || mesCheckOut > 12)
						throw 5;
					salir = true;
				}
				catch (...)
				{
					cout << "std::invalid_argument" << endl;
					cout << "Ingrese un mes entre 1 y 12" << endl;
					cout << endl;
				}
			}
			salir = false;
			while (!salir){
				try
				{
					cout << "Ingrese el año del checkOut:" << endl;
					cin >> anioCheckOut;
					if (anioCheckOut < 1900)
						throw 6;
					salir = true;
				}
				catch (...)
				{
					cout << "std::invalid_argument" << endl;
					cout << "Ingrese un año mayor a 1900" << endl;
					cout << endl;
				}
			}
			DTFecha CheckIn(diaCheckIn, mesCheckIn, anioCheckIn);
			DTFecha CheckOut(diaCheckOut, mesCheckOut, anioCheckOut);
			string email;
			salir = false;
			encontre = false;
			string nombre;
			bool esFinger;
			while (!salir){
				try{
					cout << "Por favor digite su email" << endl;
					int i = 0;
					cin >> email;
					while (i < sistema.indHuesped && !encontre   ){
						if (email == sistema.ArrHuesped[i]->getEmail()){
							encontre = true;
							nombre=sistema.ArrHuesped[i]->getNombre();
							esFinger=sistema.ArrHuesped[i]->getEsfinger();
						}
						i++;
					}
					if (!encontre)
						throw "std::invalid_argument";
					else
						salir = true;
				}
				catch (...){
					cout << "std::invalid_argument" << endl;
					cout << "El email ingresado no fue encontrado, intente denuevo" << endl;
				}
			}
			//RESERVA INDIVIDUAL
			if (cantidad == 1){ // Reserva Individual
				salir = false;
				encontre = false;
				cout << "Seleccionó la opción reserva individual." << endl;
				int pagada_int;
				bool pagada;
				cout << "Presione 1 si la reserva esta pagada, otro numero si no lo esta" << endl;
				cin >> pagada_int;
				if (pagada_int == 1)
					pagada = true;
				else
					pagada = false;
				DTReservaIndividual *reserva = new DTReservaIndividual(num_habitacion, CheckIn, CheckOut, Abierta, precio_habitacion, codigo, cantidad,pagada);
				sistema.registrarReserva(email, reserva);
			}
			//RESERVA GRUPAL
			else{ // Reserva Grupal
				cout << "Seleccionó la opción reserva grupal." << endl;
				DTHuesped **ArregloDeHuespedes = new DTHuesped *[cantidad];
				//viene cargado con un email de arriba
				int indicehuespedes=0;

				//agrego el que registra la reserva
				DTHuesped *a_agregar = new DTHuesped(email, nombre, esFinger);

				ArregloDeHuespedes[0] = a_agregar;

				indicehuespedes++;

				//pregunto datos de los otros y los agrego
				while(indicehuespedes < cantidad){
					try
					{
						cout << "Ingrese el mail del siguiente huesped" << endl;
						int i = 0;
						cin >> email;
						encontre = false;
						bool yaesta;
						while (!encontre && (i < sistema.indHuesped))
						{
							yaesta = false;
							
							if (email == sistema.ArrHuesped[i]->getEmail()){
								encontre = true;

								int iteraux = 0;
								
								while((iteraux < indicehuespedes) && (yaesta == false)){
									if(email == ArregloDeHuespedes[iteraux]->getEmail()){
										yaesta = true;
									}

									iteraux++;

								}

								if(yaesta == false){
									nombre = sistema.ArrHuesped[i]->getNombre();
									esFinger = sistema.ArrHuesped[i]->getEsfinger();

									DTHuesped *nuevo=new DTHuesped(nombre, email, esFinger);
									ArregloDeHuespedes[indicehuespedes]=nuevo;

									indicehuespedes++;

								}
							}

							i++;
						}
						
						if(yaesta){
							cout << "El email ingresado ya está en la reserva, ingrese otro mail" << endl;
							throw "std::invalid_argument";
						}

						if (!encontre){
							cout << "El email ingresado no fue encontrado, intente denuevo" << endl;
							throw "std::invalid_argument";
						}
					}
					catch (...)
					{
						cout << "std::invalid_argument" << endl;
					}
				}
				DTReservaGrupal *reserva = new DTReservaGrupal(num_habitacion, CheckIn, CheckOut, Abierta, precio_habitacion, codigo, cantidad, ArregloDeHuespedes);
				sistema.registrarReserva(email, reserva);
			
			}
			cout << "Su reserva fue registrada con exito" << endl;
		}
		break;
		case 6: {// Inicio Obtener Reservas
			cout << "Ha digitado la opcion de Obtener Reservas" << endl;
			if (sistema.indReserva == 0){
				cout << "No hay reservas registrados hasta el momento" << endl;
				break;
			}
			int day, year, month;
			bool salir = false;
			while (!salir){
				try{
					cout << "Digite el dia deseado" << endl;
					cin >> day;
					if (day < 1 || day > 31)
					{
						throw "std::invalid_argument";
					}
					salir = true;
				}
				catch (...)
				{
					cout << "std::invalid_argument" << endl;
					cout << "Ingrese un dia entre 1 y 31" << endl;
					cout << endl;
				}
			}
			salir = false;
			while (!salir)
			{
				try
				{
					cout << "Digite el mes deseado" << endl;
					cin >> month;
					if (month < 1 || month > 12)
					{
						throw "std::invalid_argument";
					}
					salir = true;
				}
				catch (...)
				{
					cout << "std::invalid_argument" << endl;
					cout << "Ingrese un mes entre 1 y 12" << endl;
					cout << endl;
				}
			}
			salir = false;
			while (!salir){
				try{
					cout << "Digite el año deseado" << endl;
					cin >> year;
					if (year < 1900)
					{
						throw "std::invalid_argument";
					}
					salir = true;
				}
				catch (...)
				{
					cout << "std::invalid_argument" << endl;
					cout << "Ingrese un año mayor a 1900" << endl;
					cout << endl;
				}
			}
			DTFecha fecha = DTFecha(day, month, year);
			int cantReservas;
			DTReserva **ArrReservas = sistema.obtenerReservas(fecha, cantReservas);
			if(cantReservas == 0){
				cout << "No hay reservas registradas para el dia seleccionado" << endl;
			}
			else{
				int i = 0;
				while (i < cantReservas)
				{
					cout << "Reserva ";
					cout << i+1;
					cout << ":" << endl;
					cout << ArrReservas[i] << endl;
					delete ArrReservas[i];
					i++;
				}
			}
			delete[] ArrReservas;
		} // Fin Obtener Reservas
		break;
		default: // Caso saliendo u otro
			cout << "Saliendo" << endl;
		}
	}
	return 0;
}