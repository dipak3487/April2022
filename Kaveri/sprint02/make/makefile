CC = g++
TH = -lpthread
IN = ../include
DB = -ljsoncpp
SR = -I../src/
RM = rm -rf
CFLAG = $(DB) -I$(IN)

#makefile for program

../bin/program: ../obj/main.o ../obj/employee.o
	$(CC)  -o ../bin/program ../obj/main.o ../obj/employee.o $(DB) $(TH)

../obj/main.o: ../src/main.cpp
	$(CC)  -g -o ../obj/main.o -c ../src/main.cpp $(CFLAG) $(SR)

../obj/employee.o: ../src/employee.cpp
	$(CC)  -g -o ../obj/employee.o -c ../src/employee.cpp $(CFLAG) $(SR)

clean:
	$(RM) ../obj/*.o ../bin/program 
                        
