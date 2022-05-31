EJECUTABLES= src/DTFecha.o src/DTHuesped.o src/Huesped.o src/DTHabitacion.o src/Habitacion.o src/DTReserva.o src/Reserva.o src/DTReservaIndividual.o src/ReservaIndividual.o src/DTReservaGrupal.o src/ReservaGrupal.o src/DTEstadia.o src/Estadia.o src/DTCalificacion.o src/Calificacion.o src/Sistema.o main.o      
#main.cpp DTReserva.cpp DTHuesped.cpp DTHabitacion.cpp DTFecha.cpp Sistema.cpp

#si cambia cualquier .o corre el codigo de abajo

testing: $(EJECUTABLES)
	@g++ $(EJECUTABLES) -o testing

#si cambia .cpp corre el codigo de abajo y lo copila

DTFecha.o: src/DTFecha.cpp include/DTFecha.h
	g++ -c DTFecha.cpp

DTHuesped.o:src/DTHuesped.cpp include/DTHuesped.h
	g++ -c DTHuesped.cpp

Huesped.o:src/Huesped.cpp include/Huesped.h
	g++ -c Huesped.cpp

DTHabitacion.o: src/DTHabitacion.cpp include/DTHabitacion.h
	g++ -c DTHabitacion.cpp

Habitacion.o: src/Habitacion.cpp include/Habitacion.h
	g++ -c Habitacion.cpp

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

DTEstadia.o: src/DTEstadia.cpp include/DTEstadia.h
	g++ -c DTEstadia.cpp

Estadia.o: src/Estadia.cpp include/Estadia.h
	g++ -c Estadia.cpp

DTCalificacion.o: src/DTCalificacion.cpp include/DTCalificacion.h
	g++ -c DTCalificacion.cpp

Calificacion.o: src/Calificacion.cpp include/Calificacion.h
	g++ -c Calificacion.cpp

Sistema.o: src/Sistema.cpp include/Sistema.h
	g++ -c Sistema.cpp

main.o: main.cpp include/imprimir.h 
	g++ -c main.cpp

clean: 
	@rm  main.o src/*.o  testing
	

