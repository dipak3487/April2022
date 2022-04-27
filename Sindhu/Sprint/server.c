#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
        char *ip = "127.0.0.1";
        int port = 5566;

        int server_sock,client_sock;
        struct sockaddr_in server_addr,client_addr;
        socklen_t addr_size;
        char buffer[1024];    //transfer info from client and server for that we need variable to store those information
        int n;

        server_sock = socket(AF_INET,SOCK_STREAM,0);
        if(server_sock < 0)
        {
                perror("socket error");
                exit(1);
        }
        printf("tcp server socket created.\n");

        memset(&server_addr,'\0',sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = port;
        server_addr.sin_addr.s_addr = inet_addr(ip);

        n = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
        if(n<0)
        {
                perror("bind error");
                exit(1);
        }
        printf("bind to port no: %d\n",port);

        listen(server_sock,5);
        printf("listening...\n");
        while(1)
        {
                addr_size = sizeof(client_addr);
                client_sock =accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
                printf("client connected,\n");
                 bzero(buffer, 1024);
                recv(client_sock, buffer, sizeof(buffer), 0);
                printf("client: %s\n", buffer);


		//Read ICCID file
		char source[] = "/home/adi/bitwise/April2022/Sindhu/Sprint/ICCID";
		char end[] = ".conf";
		strcat(buffer, end);
    		strcat(source, buffer);
    		printf("Filepath: %s\n", source);
		FILE* ptr;
    		char ch;
    		ptr = fopen(source, "a+");
    		if (NULL == ptr) {
        		printf("file can't be opened \n");
    		}
    		else{
    			printf("content of this file are \n");
    			while (!feof(ptr)) {
        			ch = fgetc(ptr);
        			printf("%c", ch);
    			}
    			fclose(ptr);
    		}

                bzero(buffer,1024);
                strcpy(buffer, "HI THIS IS SERVER.HAVE A NICE DAY!!! ");
                printf("server: %s\n", buffer);
                send(client_sock,buffer,strlen(buffer), 0);

                close(client_sock);
                printf("client disconnected.\n");

        }


        return 0;
}
