CC = g++
TH = -lpthread
IN = ../include
DB = -lsqlite3
SR = -I../src/
RM = rm -rf
CFLAG = $(DB) -I$(IN)

#makefile for program

../bin/program: ../obj/main.o ../obj/vaccine.o
	$(CC)  -o ../bin/program ../obj/main.o ../obj/vaccine.o $(DB) $(TH)

../obj/main.o: ../src/main.cpp
	$(CC)  -g -o ../obj/main.o -c ../src/main.cpp $(CFLAG) $(SR)

../obj/vaccine.o: ../src/vaccine.cpp
	$(CC)  -g -o ../obj/vaccine.o -c ../src/vaccine.cpp $(CFLAG) $(SR)

clean:
	$(RM) ../bin/program 
	$(RM) ../obj/main.o 
	$(RM) ../obj/vaccine.o

