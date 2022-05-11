system: myhead mytail mycat mytac mysort

myhead: myhead.o
	gcc -o myhead myhead.o

myhead.o: my_head/myhead.c
	gcc -c my_head/myhead.c

mytail: mytail.o
	gcc -o mytail mytail.o

mytail.o: my_tail/mytail.c
	gcc -c my_tail/mytail.c

mycat: mycat.o
	gcc -o mycat mycat.o

mycat.o: my_cat/mycat.c
	gcc -c my_cat/mycat.c

mytac: mytac.o
	gcc -o mytac mytac.o

mytac.o: my_tac/mytac.c
	gcc -c my_tac/mytac.c

mysort: mysort.o
	gcc -o mysort mysort.o

mysort.o: my_sort/mysort.c
	gcc -c my_sort/mysort.c

clean:
	rm myhead.o myhead
	rm mytail.o mytail
	rm mytac.o mytac
	rm mysort.o mysort
	rm mycat.o mycat
	
install:
	sudo cp -rf mytail /usr/local/bin/
	sudo cp -rf mytac /usr/local/bin/
	sudo cp -rf mysort /usr/local/bin/
	sudo cp -rf myhead /usr/local/bin/
	sudo cp -rf mycat /usr/local/bin/
