../bin/program: ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/HotelManager.o
<<<<<<< HEAD
	g++ -o ../bin/program ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/HotelManager.o -lm `mysql_config --cflags --libs` -lgcov
=======
		g++ -o ../bin/program ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/HotelManager.o `mysql_config --cflags --libs` -lpthread
>>>>>>> 88fe6df5b1d4fcfbf861b3832ced064ae855c97e

../obj/main.o: ../src/main.cpp
	g++ -g --coverage -o ../obj/main.o -c ../src/main.cpp  -I../include/ -I../src/ 

../obj/sql.o: ../src/sql.cpp 
	g++ -g --coverage -o ../obj/sql.o -c ../src/sql.cpp  -I../include/ -I../src/ 

../obj/HotelManager.o: ../src/HotelManager.cpp 
	g++ -g --coverage -o ../obj/HotelManager.o -c ../src/HotelManager.cpp  -I../include/ -I../src/ 

../obj/Room.o: ../src/Room.cpp
	g++ -g --coverage -o ../obj/Room.o  -c ../src/Room.cpp  -I../include/ -I../src/ 

clean:
<<<<<<< HEAD
	rm -rf ../obj/*.o ../bin/program
=======
	        rm -rf ../obj/*.o ../bin/program
>>>>>>> 88fe6df5b1d4fcfbf861b3832ced064ae855c97e
