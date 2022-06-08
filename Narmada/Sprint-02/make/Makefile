CC = g++
TH = -lpthread
IN = -I../include
DB = -lsqlite3
RM = rm -rf
CPPFLAG = $(DB)

../bin/orogram: ../obj/date.o ../obj/car.o ../obj/customer.o ../obj/rentals.o ../obj/main.o
		$(CC) ../obj/date.o ../obj/car.o ../obj/customer.o ../obj/rentals.o ../obj/main.o  $(DB) $(TH) -g -o ../bin/program

../obj/date.o:	../src/date.cpp
		$(CC) -g -o ../obj/date.o -c ../src/date.cpp $(CPPFLAG) $(IN) 

../obj/car.o:	../src/car.cpp
		$(CC) -g -o ../obj/car.o -c ../src/car.cpp $(CPPFLAG) $(IN)

../obj/customer.o: ../src/customer.cpp
		$(CC) -g -o ../obj/customer.o -c ../src/customer.cpp $(CPPFLAG) $(IN)

../obj/rentals.o: ../src/rentals.cpp
		$(CC) -g -o ../obj/rentals.o -c ../src/rentals.cpp $(CPPFLAG) $(IN)

../obj/main.o: ../src/main.cpp
		$(CC) -g -o ../obj/main.o -c ../src/main.cpp $(CPPFLAG) $(IN)

clean:
		$(RM) ../obj/*.o ../bin/program
