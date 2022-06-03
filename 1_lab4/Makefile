#ABREVIACIONES
DTI= DataType/include
DTS= DataType/src
COI= conceptos/include
COS= conceptos/src

EJECUTABLES= $(DTS)/DTFecha.o $(DTS)/DTUsuario.o $(COS)/Usuario.o $(DTS)/DTUsuarioHuesped.o $(COS)/UsuarioHuesped.o $(COS)/UsuarioEmpleado.o $(DTS)/DTHabitacion.o $(COS)/Habitacion.o $(DTS)/DTReserva.o $(COS)/Reserva.o $(DTS)/DTReservaIndividual.o $(COS)/ReservaIndividual.o $(DTS)/DTReservaGrupal.o $(COS)/ReservaGrupal.o $(DTS)/DTEstadia.o $(COS)/Estadia.o $(DTS)/DTCalificacion.o $(COS)/Calificacion.o $(COS)/Sistema.o main.o      

#si cambia cualquier .o corre el codigo de abajo

testing: $(EJECUTABLES)
	@g++ $(EJECUTABLES) -o testing

#si cambia .cpp corre el codigo de abajo y lo copila

DTFecha.o: $(DTS)/DTFecha.cpp $(DTI)/DTFecha.h
	g++ -c DTFecha.cpp

DTUsuarioHuesped.o: $(DTS)/DTUsuarioHuesped.cpp $(DTI)/DTUsuarioHuesped.h
	g++ -c DTUsuarioHuesped.cpp

UsuarioHuesped.o:$(COS)/UsuarioHuesped.cpp $(COI)/UsuarioHuesped.h
	g++ -c UsuarioHuesped.cpp

DTHabitacion.o: $(DTS)/DTHabitacion.cpp $(DTI)/DTHabitacion.h
	g++ -c DTHabitacion.cpp

Habitacion.o: $(COS)/Habitacion.cpp $(COI)/Habitacion.h
	g++ -c Habitacion.cpp

DTReserva.o: $(DTS)/DTReserva.cpp $(DTI)/DTReserva.h
	g++ -c DTReserva.cpp 

Reserva.o: $(COS)/Reserva.cpp $(COI)/Reserva.h
	g++ -c Reserva.cpp

DTReservaIndividual.o: $(DTS)/DTReservaIndividual.cpp $(DTI)/DTReservaIndividual.h
	g++ -c DTReservaIndividual.cpp

ReservaIndividual.o: $(COS)/ReservaIndividual.cpp $(COI)/ReservaIndividual.h
	g++ -c ReservaIndividual.cpp

DTReservaGrupal.o: $(DTS)/DTReservaGrupal.cpp $(DTI)/DTReservaGrupal.h
	g++ -c DTReservaGrupal.cpp

ReservaGrupal.o: $(COS)/ReservaGrupal.cpp $(COI)/ReservaGrupal.h
	g++ -c ReservaGrupal.cpp

DTEstadia.o: $(DTS)/DTEstadia.cpp $(DTI)/DTEstadia.h
	g++ -c DTEstadia.cpp 

Estadia.o: $(COS)/Estadia.cpp $(COI)/Estadia.h
	g++ -c Estadia.cpp 

DTCalificacion.o: $(DTS)/DTCalificacion.cpp $(DTI)/DTCalificacion.h
	g++ -c DTCalificacion.cpp

Calificacion.o: $(COS)/Calificacion.cpp $(COI)/Calificacion.h
	g++ -c Calificacion.cpp

Sistema.o: $(COS)/Sistema.cpp $(COI)/Sistema.h
	g++ -c Sistema.cpp

main.o: main.cpp $(COI)/imprimir.h 
	g++ -c main.cpp

clean: 
	@rm -f main.o $(COS)/*.o $(DTS)/*.o  testing
	

