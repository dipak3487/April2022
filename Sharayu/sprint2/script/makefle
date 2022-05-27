../bin/program: ../obj/main.o 
	g++ -o ../bin/program ../obj/main.o 

../obj/main.o: ../src/main.cpp
	g++ -g -o ../obj/main.o -c ../src/main.cpp 


clean:
	rm ../obj/main.o ../bin/program
