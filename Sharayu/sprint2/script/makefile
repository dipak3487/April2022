../bin/program: ../obj/main.o ../src/jsoncpp.o
	g++ -o ../bin/program ../obj/main.o ../obj/jsoncpp.o -ljsoncpp

../obj/main.o: ../src/main.cpp
	g++ -g -o ../obj/main.o -c ../src/main.cpp -ljsoncpp -I../include/ -I../src/

../obj/jsoncpp.o: ../src/jsoncpp.cpp
	g++ -g -o ../obj/jsoncpp.o -c ../jsoncpp.cpp -ljsoncpp -I../include/ -I../src/

clean:
	rm -rf ../obj ../bin/program
