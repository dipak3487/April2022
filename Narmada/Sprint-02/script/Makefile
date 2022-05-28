../bin/program: ../obj/date.o ../obj/car.o ../obj/customer.o ../obj/rentals.o ../obj/main.o
		g++ ../obj/date.o ../obj/car.o ../obj/customer.o ../obj/rentals.o ../obj/main.o -l sqlite3 -l ncurses -g -o ../bin/program

../obj/date.o:	../src/date.cpp
		g++ -g -o ../obj/date.o -c ../src/date.cpp

../obj/car.o:	../src/car.cpp
		g++ -g -o ../obj/car.o -c ../src/car.cpp

../obj/customer.o: ../src/customer.cpp
		g++ -g -o ../obj/customer.o -c ../src/customer.cpp

../obj/rentals.o: ../src/rentals.cpp
		g++ -g -o ../obj/rentals.o -c ../src/rentals.cpp

../obj/main.o: ../src/main.cpp
		g++ -g -o ../obj/main.o -c ../src/main.cpp

clean:
		rm -r ../obj/*.o ../bin/program
