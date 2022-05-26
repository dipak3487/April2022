../bin/program: ../obj/main.o ../obj/Account.o
	g++ -o ../bin/program ../obj/main.o ../obj/Account.o -ljsoncpp

../obj/main.o: ../src/main.cpp
	g++ -g -o ../obj/main.o -c ../src/main.cpp -ljsoncpp

../obj/Account.o: ../src/Account.cpp
	g++ -g -o ../obj/Account.o -c ../src/Account.cpp -ljsoncpp

clean:
	rm ../obj/main.o ../obj/Account.o ../bin/program 
