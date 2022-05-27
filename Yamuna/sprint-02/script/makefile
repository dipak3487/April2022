../bin/program: ../obj/main.o ../obj/Config.o
	mkdir ../bin/
	g++ -o ../bin/program ../obj/main.o ../obj/Config.o -ljsoncpp

../obj/main.o: ../src/main.cpp
	mkdir ../obj/
	g++ -g -o ../obj/main.o -c ../src/main.cpp -ljsoncpp -I../include/ -I../src/

../obj/Config.o: ../src/Config.cpp
	g++ -g -o ../obj/Config.o -c ../src/Config.cpp -ljsoncpp -I../include/ -I../src/

clean:
	rm -rf ../obj/main.o ../obj/Config.o ../bin/program
