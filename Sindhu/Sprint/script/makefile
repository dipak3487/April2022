cc=gcc  
MAKE=make
RM =rm

#targets 
../bin/all: client.o server.o
	$(cc) -c ../obj/client.o ../obj/server.o
server.o:    
	$(cc) -o ../obj/server.o ../src/server.c
client.o:
	$(cc) -o ../obj/client.o ../src/client.c
install:
	cp ../obj/server.o ../bin/server
	cp ../obj/client.o ../bin/client
launch: 
	gnome-terminal -t server --working-directory=/home/kanha/sprint02/April2022/Sindhu/Sprint/bin -- "./server"
	sleep 1s
	gnome-terminal -t client --working-directory=/home/kanha/sprint02/April2022/Sindhu/Sprint/bin -- "./client"	
	sleep 1s
clean:
	$(RM) ../obj/server.o
	$(RM) ../obj/client.o
	$(RM) ../bin/server
	$(RM) ../bin/client

