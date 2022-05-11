program : main.o
	gcc -o program main.o

main.o : main.c
	gcc -c main.c

clear :
	rm program main.o

install :
	sudo cp -rf sample.csv /usr/local/bin
	sudo cp -rf program /usr/local/bin/
	
