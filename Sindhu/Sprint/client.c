#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stddef.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>




int displaySim(int choice, char * str)
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
        if(choice == 3)
            strcpy(buffer, "Display Sim");
        else if(choice == 2)
            strcpy(buffer, "Query Sim");
        printf("client: %s\n",buffer);
        send(sock, buffer, strlen(buffer), 0);
        sleep(0.1);

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
    
    int choice, count=0,i;
    char str[50];
    
    
        while(1)
    {
	printf("\t\t\t|------------------------|\n");    
	printf("\t\t\t|          MENU          |\n");     
        printf("\t\t\t|------------------------|\n");
        printf("\t\t\t|1.Select ICCID          | \n");
	printf("\t\t\t|------------------------|\n");        
        printf("\t\t\t|2.Query SIM profile     |\n");
        printf("\t\t\t|------------------------|\n");
        printf("\t\t\t|3.Display SIM profile   |\n");
      	printf("\t\t\t|------------------------|  \n");
        printf("\t\t\t|4.Exit                  |\n");
        printf("\t\t\t|------------------------| \n");
        printf("Enter your choice :  ");
        scanf("%d", &choice);

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
                           printf("Valid number:-> \n 1.Select ICCID (%s)\n",str);
                           printf("----------------------------------------------\n");
                       } 
                     	else 
                          printf("Invalid number , number shopuls start with 89\n");
                   }
                   else
                    printf("Invalid number no enter no between 18 to 22\n");
                   
                   
                   break;

            case 2:  displaySim(choice, str);
                     printf("----------------------------------------------\n");
                    
                   break;

            case 3:  displaySim(choice, str);
              			printf("----------------------------------------------\n");
                   break;

            case 4:exit(0);
        }
    }
    return 0;
}
