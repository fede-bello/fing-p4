EJECUTABLES= main.o src/DTReserva.o src/Reserva.o src/DTReservaIndividual.o src/ReservaIndividual.o src/DTReservaGrupal.o  src/ReservaGrupal.o src/DTHuesped.o src/Huesped.o src/DTHabitacion.o src/Habitacion.o src/DTFecha.o src/Sistema.o 
#main.cpp DTReserva.cpp DTHuesped.cpp DTHabitacion.cpp DTFecha.cpp Sistema.cpp

#si cambia cualquier .o corre el codigo de abajo

testing: $(EJECUTABLES)
	@g++ $(EJECUTABLES) -o testing

#si cambia .cpp corre el codigo de abajo y lo copila

main.o: main.cpp #include/imprimir.h 
	g++ -c main.cpp

DTReserva.o: src/DTReserva.cpp include/DTReserva.h
	g++ -c DTReserva.cpp

Reserva.o: src/Reserva.cpp include/Reserva.h
	g++ -c Reserva.cpp

DTReservaIndividual.o: src/DTReservaIndividual.cpp include/DTReservaIndividual.h
	g++ -c DTReservaIndividual.cpp

ReservaIndividual.o: src/ReservaIndividual.cpp include/ReservaIndividual.h
	g++ -c ReservaIndividual.cpp

DTReservaGrupal.o: src/DTReservaGrupal.cpp include/DTReservaGrupal.h
	g++ -c DTReservaGrupal.cpp

ReservaGrupal.o: src/ReservaGrupal.cpp include/ReservaGrupal.h
	g++ -c ReservaGrupal.cpp

DTHuesped.o:src/DTHuesped.cpp include/DTHuesped.h
	g++ -c DTHuesped.cpp

Huesped.o:src/Huesped.cpp include/Huesped.h
	g++ -c Huesped.cpp

DTHabitacion.o: src/DTHabitacion.cpp include/DTHabitacion.h
	g++ -c DTHabitacion.cpp

Habitacion.o: src/Habitacion.cpp include/Habitacion.h
	g++ -c Habitacion.cpp

DTFecha.o: src/DTFecha.cpp include/DTFecha.h
	g++ -c DTFecha.cpp

Sistema.o: src/Sistema.cpp include/Sistema.h
	g++ -c Sistema.cpp

clean: 
	@rm  main.o src/*.o  testing
	

