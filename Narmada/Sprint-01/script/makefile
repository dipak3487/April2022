../bin/program : ../obj/main.o
	gcc -o ../bin/program ../obj/main.o

../obj/main.o : ../src/main.c
	gcc -g -o ../obj/main.o -c ../src/main.c

clean :
	rm ../bin/program ../obj/main.o

install :
	sudo cp -rf ../data/sample.csv /usr/local/bin
	sudo cp -rf ../bin/program /usr/local/bin/
	
