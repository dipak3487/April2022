cc=gcc      // this is the variable which is used in the target.
MAKE=make
RM =rm

#targets .
all: client.c server.c
    $(cc) -o client client.c    
    $(cc) -o server server.c
    gnome-terminal -t server --working-directory=/home/techbeamers -e "./server"
    sleep 10s 
    $(MAKE) client_target   


#another target for client
client_target:
    ./client  


clean:server client
    $(RM) server
    $(RM) client

