#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
   
    
  
int tele[5][5]= {};
  FILE* fp = fopen("tele.csv", "r");
 
    if (!fp)
        printf("Can't open file\n");
 
    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
 
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
 
            // Splitting the data
            char* value = strtok(buffer, ", ");
            int A_network, B_network , DiffTime, Stime,Etime;
            while (value) {
                // Column 1
                if (column == 0) {
                  
                }
 
                // Column 2
                if (column == 1) {
                    
                }
 
                // Column 3
                if (column == 2) {
                   
                    Stime = strtol(value, NULL, 10);
                }

                if (column == 3) {
                   
                    Etime = strtol(value, NULL, 10);
                }

                if (column == 4) {
                   
                    if (strcmp(value, "Airtel") == 0){
                        A_network = 0;
                    }else if (strcmp(value, "Jio") == 0) {
                        A_network = 1;
                    }else if  (strcmp(value, "Vi") == 0) {
                        A_network = 2;
                    }else if  (strcmp(value, "BSNL") == 0) {
                        A_network = 3;
                    }
                }

                if (column == 5) {
                    
                    if (strcmp(value, "Airtel") == 0){
                        B_network = 0;
                    }else if (strcmp(value, "Jio") == 0) {
                        B_network = 1;
                    }else if  (strcmp(value, "Vi") == 0) {
                        B_network = 2;
                    }else if  (strcmp(value, "BSNL") == 0) {
                        B_network = 3;
                    }
                }
 
                
                value = strtok(NULL, ",");
                column++;
            }
            DiffTime = (Etime - Stime);
            tele[A_network][B_network] =  tele[A_network][B_network] + DiffTime;        
           
        }

        
        // Close the file
        fclose(fp);
    }

// for  ( int i=0;i<4;i++){
//     for (int j=0;j<4;j++){
//         printf(" %d",tele[i][j]);
//     }
//     printf("\n");
// }

   // int inp[3][3] = {{0,1,5},{0,1,4},{1,0,3}};

    //int tele[3][3]= {};
   
    // for(int i=0;i<3;i++){
    //         tele[inp[i][0]][inp[i][1]] = tele[inp[i][0]][inp[i][1]] + inp[i][2];
    // }

float price ;
    if (tele[0][1] > tele[1][0]) {
         price = (tele[0][1]-tele[1][0])/100.00;
        printf("Airtel to Jio - RS %.2f \n",price);
    } else if (tele[0][1] < tele[1][0]) {
        price = (tele[1][0]-tele[0][1])/100.00;
        printf("Jio to Airtel - RS %.2f \n",price);
    }
    
    if (tele[0][2] > tele[2][0]) {
        printf("Airtel to VI - RS %.2f\n",(tele[0][2]-tele[2][0])/100.00);
    } else if (tele[0][2] < tele[2][0]) {
        printf("VI to Airtel - RS %.2f\n",(tele[2][0]-tele[0][2])/100.00);
    }
    if (tele[0][3] > tele[3][0]) {
        printf("Airtel to BSNL - RS %.2f\n",(tele[0][3]-tele[3][0])/100.00);
    } else if (tele[0][3] < tele[3][0]) {
        printf("BSNL to Airtel - RS %.2f\n",(tele[3][0]-tele[0][3])/100.00);
    }
    
    if (tele[1][2] > tele[2][1]) {
        price = (tele[1][2]-tele[2][1])/100.00;
        printf("Jio to VI - RS %.2f \n",price);
    } else if (tele[1][2] < tele[2][1]) {
        price = (tele[2][1]-tele[1][2])/100.00;
        printf("VI to Jio - RS %.2f \n",price);
    }
     if (tele[1][3] > tele[3][1]) {
         price = (tele[1][3]-tele[3][1])/100.00;
        printf("Jio to BSNL - RS %.2f \n",price);
    } else if (tele[1][3] < tele[3][1]) {
        price = (tele[3][1]-tele[1][3])/100.00;
        printf("BSNL to Jio - RS %.2f \n",price);
    }
     
    if (tele[2][3] > tele[3][2]) {
        price = (tele[3][2]-tele[2][3])/100.00;
        printf("VI to BSNL - RS %.2f \n",price);
       
    } else if (tele[2][3] < tele[3][2]) {
         price = (tele[3][2]-tele[2][3])/100.00;
        printf("BSNL to VI - RS %.2f \n",price);
    }

    return 0;
}

