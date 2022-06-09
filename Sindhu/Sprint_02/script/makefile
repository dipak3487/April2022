CC = g++
<<<<<<< HEAD
TH = -lpthread
IN = -I ../include
DB = -lsqlite3
SR = ../src/
RM = rm -rf
CFLAG = $(DB) -I$(IN)
=======
CFLAG = -o
CMP = -c
OBJPRO = ../bin/program
OBJMAIN = ../obj/main.o
OBJVAC = ../obj/vaccine.o
SRCMN = ../src/main.cpp
SRVAC = ../src/vaccine.cpp
DB = -lsqlite3
TH = -lpthread
SR = -I../include/
BINPRO = ../bin/program
>>>>>>> 897cced007e38e6cc6fe08f5706242f31ef5f399

#makefile for program

$(BINPRO): $(OBJMAIN) $(OBJVAC)
	$(CC) $(CFLAG) $(OBJMN) $(SRCMN) $(OBJVAC) $(DB) $(TH)

<<<<<<< HEAD
../obj/main.o: ../src/main.cpp
	$(CC)  -g -o ../obj/main.o -c ../src/main.cpp $(CFLAG) $(SR) $(IN)

../obj/vaccine.o: ../src/vaccine.cpp
	$(CC)  -g -o ../obj/vaccine.o -c ../src/vaccine.cpp $(CFLAG) $(SR) $(IN)

clean:
	$(RM) ../bin/program ../obj/vaccine.o ../bin/program
=======
../obj/main.o: $(SRCMN)
	$(CC) $(CFLAG) $(OBJMAIN) $(SRCMN) $(DB) $(SR)

../obj/vaccine.o: $(SRVAC)
	$(CC) $(CFLAG) $(OBJVAC) $(SRCVAC) $(DB) $(SR)

clean:
	$(RM) $(BINPRO)
	$(RM) $(OBJMAIN) 
	$(RM) $(OBJVAC)
>>>>>>> 897cced007e38e6cc6fe08f5706242f31ef5f399

