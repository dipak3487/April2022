../bin/program: ../obj/main.o
	mkdir ../bin
	g++ -o ../bin/program ../obj/main.o

../obj/main.o: ../src/main.cpp
	mkdir ../obj
	g++ -o ../obj/main.o -c ../src/main.cpp 

clean:
	rm ../bin/program ../obj/main.o

