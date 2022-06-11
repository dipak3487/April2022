CC = g++
TH = -lpthread
IN = -I../include
RM = rm -rf

../bin/program: ../obj/main.o ../obj/Student.o ../obj/jsoncpp.o
	g++ -o ../bin/program ../obj/main.o ../obj/Student.o ../obj/jsoncpp.o -ljsoncpp $(TH)

../obj/main.o: ../src/main.cpp
	g++ -std=c++17 -g -o ../obj/main.o -c ../src/main.cpp -I../include/ -I../src/

../obj/Student.o: ../src/Student.cpp
	g++ -std=c++17 -g -o ../obj/Student.o -c ../src/Student.cpp -I../include/ -I../src/

../obj/jsoncpp.o: ../src/jsoncpp.cpp
	g++ -std=c++17 -g -o ../obj/jsoncpp.o -c ../src/jsoncpp.cpp -I../include/ -I../src/

clean:
	rm ../obj/* ../bin/program
