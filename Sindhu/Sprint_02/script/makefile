../bin/program: ../obj/main.o ../obj/vaccine.o
	g++ -o ../bin/program ../obj/main.o ../obj/vaccine.o -lsqlite3 -lpthread

../obj/main.o: ../src/main.cpp

	#mkdir ../obj/

	g++ -g -o ../obj/main.o -c ../src/main.cpp -lsqlite3 -I../include/ -I../src/

../obj/vaccine.o: ../src/vaccine.cpp
	g++ -g -o ../obj/vaccine.o -c ../src/vaccine.cpp -lsqlite3 -I../include/ -I../src/

clean:
	rm -rf ../bin/program ../obj/main.o ../obj/vaccine.o

