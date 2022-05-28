../bin/program: ../obj/main.o ../obj/UI.o ../obj/Bus.o
	#mkdir ../bin/
	g++ -o ../bin/program ../obj/main.o ../obj/UI.o ../obj/Bus.o -ljsoncpp

../obj/main.o: ../src/main.cpp
	#mkdir ../obj/
	g++ -g -o ../obj/main.o -c ../src/main.cpp -ljsoncpp -I../include/ -I../src/

../obj/UI.o: ../src/UI.cpp
	g++ -g -o ../obj/UI.o -c ../src/UI.cpp -ljsoncpp -I../include/ -I../src/

../obj/Bus.o: ../src/Bus.cpp
	g++ -g -o ../obj/Bus.o -c ../src/Bus.cpp -ljsoncpp -I../include/ -I../src/

clean:
	rm -rf ../obj/main.o ../obj/UI.o ../obj/Bus.o ../bin/program
