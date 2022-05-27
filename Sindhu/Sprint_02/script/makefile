<<<<<<< HEAD
program : main.o
	gcc -o program main.o
main.o : main.cpp
	gcc -c main.cpp 
clean :
	rm program main.o
=======
../bin/program: ../obj/main.o ../obj/employee.o
	g++ -o ../bin/program ../obj/main.o ../obj/employee.o -ljsoncpp

../obj/main.o: ../src/main.cpp
	#mkdir ../obj/
	g++ -g -o ../obj/main.o -c ../src/main.cpp -ljsoncpp -I../include/ -I../src/

../obj/employee.o: ../src/employee.cpp
	g++ -g -o ../obj/employee.o -c ../src/employee.cpp -ljsoncpp -I../include/ -I../src/

clean:
	rm -rf ../obj ../bin/program
>>>>>>> c11ca685f2e7968b415dc95469a7b2549e6d6e81
