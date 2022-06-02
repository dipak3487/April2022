../bin/program: ../obj/main.o ../obj/Account.o
	g++ -o ../bin/program  ../obj/main.o ../obj/Account.o -lpthread

../obj/main.o: ../src/main.cpp
	#mkdir ../obj/
	g++ -g -o ../obj/main.o -c ../src/main.cpp -I../include/ -I../src/

../obj/Account.o: ../src/Account.cpp
	g++ -g -o ../obj/Account.o -c ../src/Account.cpp -I../include/ -I../src/

clean:
	rm ../obj/main.o ../obj/Account.o ../bin/program 
