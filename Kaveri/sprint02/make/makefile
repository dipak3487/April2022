../bin/program: ../obj/main.o ../obj/employee.o
	g++ -o ../bin/program ../obj/main.o ../obj/employee.o -ljsoncpp -lpthread

../obj/main.o: ../src/main.cpp
	mkdir ../obj/
	g++ -g -o ../obj/main.o -c ../src/main.cpp -ljsoncpp -I../include/ -I../src/

../obj/employee.o: ../src/employee.cpp
	g++ -g -o ../obj/employee.o -c ../src/employee.cpp -ljsoncpp -I../include/ -I../src/

clean:
	rm -rf ../obj ../bin/program

