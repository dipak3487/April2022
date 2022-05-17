mytail: mytail.o
	gcc -o mytail mytail.o

mytail.o: mytail.c
	gcc -c mytail.c

clean:
	rm mytail.o mytail
install: 
	sudo cp -rf mytail /usr/local/bin/

