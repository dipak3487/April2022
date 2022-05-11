mycat: mycat.o
	gcc -o mycat mycat.o

mycat.o: mycat.c
	gcc -c mycat.c 

clean:
	rm mycat mycat.o
install:
	sudo cp -rf mycat /usr/local/bin/
