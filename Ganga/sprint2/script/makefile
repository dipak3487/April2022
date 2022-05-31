../bin/program: ../obj/main.o ../obj/Bank.o
	g++ -o ../bin/program  ../obj/main.o ../obj/Bank.o -lpthread

../obj/main.o: ../src/main.cpp
	#mkdir ../obj/
	g++ -g -o ../obj/main.o -c ../src/main.cpp -I../include/ -I../src/

../obj/Bank.o: ../src/Bank.cpp
	g++ -g -o ../obj/Bank.o -c ../src/Bank.cpp -I../include/ -I../src/

clean:
	rm ../obj/main.o ../obj/Bank.o ../bin/program 
