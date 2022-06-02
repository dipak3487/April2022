#ifndef MAKEFILE_SPRINT02
#define MAKEFILE_SPRINT02
#g++ (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
#Copyright (C) 2019 Free Software Foundation, Inc.


../bin/program: ../obj/date.o ../obj/car.o ../obj/customer.o ../obj/rentals.o ../obj/main.o
		g++ ../obj/date.o ../obj/car.o ../obj/customer.o ../obj/rentals.o ../obj/main.o -l sqlite3 -lpthread -l ncurses -g -o ../bin/program

../obj/date.o:	../src/date.cpp
		g++ -g -o ../obj/date.o -c ../src/date.cpp -I../include/

../obj/car.o:	../src/car.cpp
		g++ -g -o ../obj/car.o -c ../src/car.cpp -I../include/

../obj/customer.o: ../src/customer.cpp
		g++ -g -o ../obj/customer.o -c ../src/customer.cpp -I../include/

../obj/rentals.o: ../src/rentals.cpp
		g++ -g -o ../obj/rentals.o -c ../src/rentals.cpp -I../include/

../obj/main.o: ../src/main.cpp
		g++ -g -o ../obj/main.o -c ../src/main.cpp -I../include/

clean:
		rm -r ../obj/*.o ../bin/program

#endif
