system: ../bin/myhead ../bin/mytail ../bin/mycat ../bin/mytac ../bin/mysort

../bin/myhead: ../obj/myhead.o
	gcc -o ../bin/myhead ../obj/myhead.o

../obj/myhead.o: ../src/myhead.c
	gcc -o ../obj/myhead.o -c ../src/myhead.c

../bin/mytail: ../obj/mytail.o
	gcc -o ../bin/mytail ../obj/mytail.o

../obj/mytail.o: ../src/mytail.c
	gcc -o ../obj/mytail.o -c ../src/mytail.c

../bin/mycat: ../obj/mycat.o
	gcc -o ../bin/mycat ../obj/mycat.o

../obj/mycat.o: ../src/mycat.c
	gcc -o ../obj/mycat.o -c ../src/mycat.c

../bin/mytac: ../obj/mytac.o
	gcc -o ../bin/mytac ../obj/mytac.o

../obj/mytac.o: ../src/mytac.c
	gcc -o ../obj/mytac.o -c ../src/mytac.c

../bin/mysort: ../obj/mysort.o
	gcc -o ../bin/mysort ../obj/mysort.o

../obj/mysort.o: ../src/mysort.c
	gcc -o ../obj/mysort.o -c ../src/mysort.c

clean:
	rm ../obj/myhead.o ../bin/myhead
	rm ../obj/mytail.o ../bin/mytail
	rm ../obj/mytac.o ../bin/mytac
	rm ../obj/mysort.o ../bin/mysort
	rm ../obj/mycat.o ../bin/mycat
	
install:
	sudo cp -rf ../bin/mytail /usr/local/bin/
	sudo cp -rf ../bin/mytac /usr/local/bin/
	sudo cp -rf ../bin/mysort /usr/local/bin/
	sudo cp -rf ../bin/myhead /usr/local/bin/
	sudo cp -rf ../bin/mycat /usr/local/bin/
