#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stddef.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int connection(char * str)
{
	char *ip = "127.0.0.1";
        int port = 5566;

        int sock;
        struct sockaddr_in addr;
        socklen_t addr_size;
        char buffer[1024];    //transfer info from client and server for that we need variable to store those information
        int n;

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 0)
        {
                perror("socket error");
                exit(1);
        }
        printf("tcp server socket created.\n");

        memset(&addr,'\0',sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = port;
        addr.sin_addr.s_addr = inet_addr(ip);

        connect(sock, (struct sockaddr*)&addr, sizeof(addr));
        printf("connected to server.\n");

        bzero(buffer,1024);
        strcpy(buffer, str);
        printf("client: %s\n",buffer);
        send(sock, buffer, strlen(buffer), 0);

        bzero(buffer,1024);
        recv(sock, buffer, sizeof(buffer), 0);
        printf("server: %s\n", buffer);

        close(sock);
        printf("disconnected from the server.\n");

        return 0;
}


int main()
{

    int choice, n1, count=0,i;
    char  str[50];
    
    while(1)
    {
        printf("1.Select ICCID  \n");
        printf("2.Query SIM profile \n");
        printf("3.Display SIM profile \n");
        printf("4.Exit \n\n\n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("enter the iccid no:\n");
                   scanf("%s",str);
                   i= strlen(str);
                   //printf("%d\n",i);
                   if(i>=18&&i<=22)
                   {
                       if(str[0]=='8'&&str[1]=='9')
                       {
                           printf("Valid number \n");
                           connection(str);
                       }
                     	else 
                          printf("Invalid number\n");
                   }
                   break;

            case 2:printf("enter the iccid no which u want to delete:");
                   scanf("%d",&n1);
                   break;

            case 3:
                   break;

            case 4:exit(0);
        }

        return 0;
    }
}
