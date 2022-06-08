
CC = g++
TH = -lpthread
IN = -I../include/
DB = -lm `mysql_config --cflags --libs`
RM = rm -rf
CPPFLAG = $(DB)


../bin/program: ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/hotelManager.o

	$(CC) -o ../bin/program ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/hotelManager.o $(DB) -lgcov $(TH)


../obj/main.o: ../src/main.cpp
	$(CC) -g --coverage -o ../obj/main.o -c ../src/main.cpp $(CPPFLAG) $(IN) 

../obj/sql.o: ../src/sql.cpp 
	$(CC) -g --coverage -o ../obj/sql.o -c ../src/sql.cpp  $(CPPFLAG) $(IN) 

../obj/hotelManager.o: ../src/hotelManager.cpp 
	$(CC) -g --coverage -o ../obj/hotelManager.o -c ../src/hotelManager.cpp  $(CPPFLAG) $(IN) 

../obj/Room.o: ../src/Room.cpp
	$(CC) -g --coverage -o ../obj/Room.o  -c ../src/Room.cpp  $(CPPFLAG) $(IN) 

clean:

	$(RM) ../obj/*.o ../bin/program

	        

