../bin/program: ../obj/main.o ../obj/vaccine.o
	g++ -o ../bin/program ../obj/main.o ../obj/vaccine.o -lsqlite3

../obj/main.o: ../src/main.cpp
<<<<<<< HEAD
	#mkdir ../obj/
=======
>>>>>>> f3ee2194e090b1d1a4bc21f34d9b23747bc4d546
	g++ -g -o ../obj/main.o -c ../src/main.cpp -lsqlite3 -I../include/ -I../src/

../obj/vaccine.o: ../src/vaccine.cpp
	g++ -g -o ../obj/vaccine.o -c ../src/vaccine.cpp -lsqlite3 -I../include/ -I../src/

clean:
	rm -rf ../bin/program ../obj/main.o ../obj/vaccine.o

