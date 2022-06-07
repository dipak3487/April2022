../bin/program: ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/hotelManager.o
	g++ -o ../bin/program ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/hotelManager.o -lm `mysql_config --cflags --libs` -lgcov

../obj/main.o: ../src/main.cpp
	g++ -g --coverage -o ../obj/main.o -c ../src/main.cpp  -I../include/ -I../src/ 

../obj/sql.o: ../src/sql.cpp 
	g++ -g --coverage -o ../obj/sql.o -c ../src/sql.cpp  -I../include/ -I../src/ 

../obj/hotelManager.o: ../src/hotelManager.cpp 
	g++ -g --coverage -o ../obj/hotelManager.o -c ../src/hotelManager.cpp  -I../include/ -I../src/ 

../obj/Room.o: ../src/Room.cpp
	g++ -g --coverage -o ../obj/Room.o  -c ../src/Room.cpp  -I../include/ -I../src/ 

clean:
	rm -rf ../obj/*.o ../bin/program
