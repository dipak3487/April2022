../bin/program: ../obj/main.o ../obj/Config.o
	g++ -o ../bin/program ../obj/main.o ../obj/Config.o -ljsoncpp

../obj/main.o: ../src/main.cpp
	g++ -g -c ../src/main.cpp -ljsoncpp

../obj/Config.o: ../src/Config.cpp
	g++ -g -c ../src/Config.cpp -ljsoncpp

clean:
	rm ../obj/main.o ../obj/Config.o ../bin/program 
