#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main() {
    
   
    int month,year;
    float perSec;
    
    printf("\nEnter Cost of per sec ( in paise):");
    scanf("%f", &perSec);

    printf("Enter Month (01-12) :");
    scanf("%d", &month);
    printf("Enter Year :");
    scanf("%d", &year);
    
    
  
    int tele[4][4]= {};
    FILE* fp = fopen("tele.csv", "r");
 
    if (!fp)
        printf("Can't open file\n");
 
    else {
        // Here we have taken size of
        // array 1024 
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

                // Column 3 Start Time
                if (column == 2) {
                    Stime = strtol(value, NULL, 10);
                }

                // Column 4 End Time
                if (column == 3) {
                    Etime = strtol(value, NULL, 10);
                }

                // Column 5 - A_Network
                if (column == 4) {
                    if (strcmp(value, "Airtel") == 0){                     //assign a values to networks
                        A_network = 0;
                    }else if (strcmp(value, "Jio") == 0) {
                        A_network = 1;
                    }else if  (strcmp(value, "Vi") == 0) {
                        A_network = 2;
                    }else if  (strcmp(value, "BSNL") == 0) {
                        A_network = 3;
                    }
                }

                // Column 5 - B_Network
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
 
                // fetch next value
                value = strtok(NULL, ",");
                column++;
            }

            // convert timestamp into time 
            struct tm  *ts;
            char   mon[80];
            char   yr[80];
            time_t t = (time_t)Etime;     //convert into time_t data type
            ts = localtime(&t);           //timestamp to time
            strftime(mon, sizeof(mon), "%m", ts); //fetch month
            strftime(yr, sizeof(yr), "%Y", ts);
            int end_m = atoi(mon);    //str into integer
            int end_y = atoi(yr);


            //check end time is in given month,year
            if(month==end_m && year==end_y){
            DiffTime = (Etime - Stime);                                 
            tele[A_network][B_network] =  tele[A_network][B_network] + (DiffTime*perSec);   
            }    
           
        }
        printf("\nBefore Settlement :\n");

        printf("Airtel to Jio- %d\n",tele[0][1]);
        printf("Jio to Airtel- %d\n",tele[1][0]);
        printf("Airtel to Vi- %d\n",tele[0][2]);
        printf("Vi to Airtel- %d\n",tele[2][0]);
        printf("Airtel to BSNL- %d\n",tele[0][3]);
        printf("BSNL to Airtel- %d\n",tele[3][0]);
        printf("Jio to Vi- %d\n",tele[1][2]);
        printf("vi to Jio- %d\n",tele[2][1]);
        printf("Jio to BSNL- %d\n",tele[1][3]);
        printf("BSNL to Jio- %d\n",tele[3][1]);
        printf("Vi to BSNL- %d\n",tele[2][3]);
        printf("BSNL to Vi- %d\n",tele[3][2]);
        // Close the file
        fclose(fp);
    }

    printf("\nAfter Settlement :\n");
    float price ;

    // fetch result 
    // example if Airtel to Jio > Jio to Airtel {
    //     then -> Airtel need to pay Jio requried amount 
    // } else if Airtel to Jio < Jio to Airtel {
    //     then -> Jio need to pay Airtel requried amount 
    // }


    if (tele[0][1] > tele[1][0]) {
         price = (tele[0][1]-tele[1][0])/100.00;            // /100.00 (to convert into Rs)
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
        price = (tele[2][3]-tele[3][2])/100.00;
        printf("VI to BSNL - RS %.2f \n",price);
       
    } else if (tele[2][3] < tele[3][2]) {
         price = (tele[3][2]-tele[2][3])/100.00;
        printf("BSNL to VI - RS %.2f \n",price);
    }else
    {
    printf("Data Not Found\n");
    }
    return 0;
}

