CC = g++
TH = -lpthread
IN = ../include
DB = -ljsoncpp
SR = -I../src/
RM = rm -rf
CFLAG = $(DB) -I$(IN)

#makefile for program

../bin/program: ../obj/main.o ../obj/Bus.o ../obj/UI.o
	$(CC)  -o ../bin/program ../obj/main.o ../obj/Bus.o ../obj/UI.o $(DB) $(TH)

../obj/main.o: ../src/main.cpp
	mkdir ../obj
	$(CC)  -g -o ../obj/main.o -c ../src/main.cpp $(CFLAG) $(SR)

../obj/Bus.o: ../src/Bus.cpp
	$(CC)  -g -o ../obj/Bus.o -c ../src/Bus.cpp $(CFLAG) $(SR)

../obj/UI.o: ../src/UI.cpp
	$(CC)  -g -o ../obj/UI.o -c ../src/UI.cpp $(CFLAG) $(SR)

clean:
	$(RM) ../obj ../bin/program 


