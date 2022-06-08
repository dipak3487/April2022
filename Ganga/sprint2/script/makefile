CC = g++
TH = -lpthread
IN = ../include
SR = -I../src/
RM = rm -rf
CFLAG = $(DB) -I$(IN)

#makefile for program


../bin/program: ../obj/main.o ../obj/Account.o
	$(CC) -o ../bin/program  ../obj/main.o ../obj/Account.o $(DB) $(TH)

../obj/main.o: ../src/main.cpp
	#mkdir ../obj/
	$(CC) -g -o ../obj/main.o -c ../src/main.cpp $(CFLAG) $(SR)

../obj/Account.o: ../src/Account.cpp
	$(CC) -g -o ../obj/Account.o -c ../src/Account.cpp $(CFLAG) $(SR)

clean:
	$(RM) ../obj/main.o ../obj/Account.o ../bin/program 