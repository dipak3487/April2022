
../bin/program: ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/hotelManager.o
<<<<<<< HEAD
	        g++ -o ../bin/program ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/hotelManager.o `mysql_config --cflags --libs`
=======
<<<<<<< HEAD
	g++ -o ../bin/program ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/hotelManager.o `mysql_config --libs`
=======
	        g++ -o ../bin/program ../obj/main.o ../obj/Room.o ../obj/sql.o ../obj/hotelManager.o `mysql_config --libs`
>>>>>>> 73144e7752046bcd6eb764e5a5200f80e7fe78e3
>>>>>>> 074095a469a9bd1acc257a5a4716bc1ac2f5489e

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
