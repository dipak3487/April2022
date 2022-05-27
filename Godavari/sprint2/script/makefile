<<<<<<< HEAD
../bin/program: ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/hotelManager.o
	        g++ -o ../bin/program ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/hotelManager.o `mysql_config --libs`

../obj/main.o: ../src/main.cpp
	                #mkdir ../obj/
		g++ -g -o ../obj/main.o -c ../src/main.cpp  -I../include/ -I../src/

../obj/sql.o: ../src/sql.cpp
	        g++ -g -o ../obj/sql.o -c ../src/sql.cpp  -I../include/ -I../src/

../obj/hotelManager.o: ../src/hotelManager.cpp
	        g++ -g -o ../obj/hotelManager.o -c ../src/hotelManager.cpp  -I../include/ -I../src/

../obj/Room.o: ../src/Room.cpp
	        g++ -g -o ../obj/Room.o -c ../src/Room.cpp  -I../include/ -I../src/

clean:
	        rm -rf ../obj*.o ../bin/program
=======

../bin/program: ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/hotelManager.o
	g++ -o ../bin/program ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/hotelManager.o `mysql_config --libs`

../obj/main.o: ../src/main.cpp
		#mkdir ../obj/
	g++ -g -o ../obj/main.o -c ../src/main.cpp  -I../include/ -I../src/

../obj/sql.o: ../src/sql.cpp
	g++ -g -o ../obj/sql.o -c ../src/sql.cpp  -I../include/ -I../src/

../obj/hotelManager.o: ../src/hotelManager.cpp
	g++ -g -o ../obj/hotelManager.o -c ../src/hotelManager.cpp  -I../include/ -I../src/

../obj/Room.o: ../src/Room.cpp
	g++ -g -o ../obj/Room.o -c ../src/Room.cpp  -I../include/ -I../src/

clean:
	rm -rf ../obj*.o ../bin/program
>>>>>>> 666299f52307365005d0e01830b6e93177b83c15
