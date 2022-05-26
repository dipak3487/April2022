#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 2000

	//Storing the values in column records
    struct Element
       {
        char country[100];
        char area[100];
        char birthrate[100];
		char curaccntblnc[100];
		char deathrate[100];
		char debt[100];
		char electricityconsu[100];
		char electricityproduct[100];
		char exports[100];
		char gdp[100];
		char gdppercapita[100];
		char gdprealgrowth[100];
        int st;
       };
	
	//Method Declaration
	void desendingOrderSort(struct Element elements[]);
	void convertionChartoDouble(struct Element elements[]);
	void getRichestCountryNameByGdp(struct Element elements[]);
	void getPoorestCountryNameByGdp(struct Element elements[]);
	void ascendingOrderdeathrateSort(struct Element elements[]);
	void getHappiestCountryNameByDeathRate(struct Element elements[]);
	int compare (double a, double b);	

	//Main execution Started
    int main() {

        int i,choice;
        struct Element elements[MAXLEN];
        FILE * fpointer = fopen("csvfile.csv", "r");
        char buffer[1024]; // Define a really big string to hold the line of text in
        char *field;
        int field_number;

        while(fgets(buffer,1024,fpointer))
            {
            field_number=0;
            field=strtok(buffer,","); // Splitting the values with comma
            while(field)
              {
               switch(field_number)
                {
                  case 0:
                  strcpy(elements[i].country,field);
                  break;
                  case 1:
                  strcpy(elements[i].area,field);
                  break;
                  case 2:
                  strcpy(elements[i].birthrate,field);
                  break;
				   case 3:
                  strcpy(elements[i].curaccntblnc,field);
                  break;
				   case 4:
                  strcpy(elements[i].deathrate,field);
                  break;
				   case 5:
                  strcpy(elements[i].debt,field);
                  break;
				   case 6:
                  strcpy(elements[i].electricityconsu,field);
                  break;
				  case 7:
                  strcpy(elements[i].electricityproduct,field);
                  break;
				  case 8:
                  strcpy(elements[i].exports,field);
                  break;
				  case 9:
                  strcpy(elements[i].gdp,field);
                  break;
				  case 10:
                  strcpy(elements[i].gdppercapita,field);
                  break;
				  case 11:
                  strcpy(elements[i].gdprealgrowth,field);
                  break;
                  case 12:
                  elements[i].st=atoi(field);
                  break;
                }
             field=strtok(NULL,","); // Get next field
             field_number++;
             }
           i++; // Move the index for elements to the next one
          }
		convertionChartoDouble(elements);
		desendingOrderSort(elements);
		ascendingOrderdeathrateSort(elements);
		
		printf("\n\nSharayu team project\n\n");
		while(1)
		{
			printf("1. Top Richest Countries \n");
			printf("2. Top Poorest Countries \n");
			printf("3. Top Happiest Countries \n");
			printf("4. Exit\n\n\n");
			printf("Enter your option here: ");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1:
						//Geting the Richest Countries 
						getRichestCountryNameByGdp(elements);
						break;
				case 2:
						//Geting the Poorest Countries 
						getPoorestCountryNameByGdp(elements);
						break;
				case 3:
						//Geting the Happiest Countries 
						getHappiestCountryNameByDeathRate(elements);
						break;
				case 4:
					exit(0);
			}		
			
		}
		fclose(fpointer);
		//return 0;

    }


	//Initialize array     
	double gdparray[12]={};
	double deathratearray[12]={};
	char *gdptr;
	char *deathrateptr;
	double gdpdouble;
	double deathratedouble;
	
	//converting the values char to Double
    void convertionChartoDouble(struct Element elements[])
    {
   
		for (int i=0; i < 12; i++) {
			deathratedouble = strtod(elements[i].deathrate, &deathrateptr);
			gdpdouble = strtod(elements[i].gdprealgrowth, &gdptr);
			if(gdpdouble != 0.000000){	
				gdparray[i] = gdpdouble;
			}
			if(deathratedouble != 0.000000){	
				deathratearray[i] = deathratedouble;
			}
		}
	}
	
	//Sort the gdp array values by using desending Order
	void desendingOrderSort(struct Element elements[])
	{
		
		double temp = 0; 
		int length = sizeof(gdparray)/sizeof(gdparray[0]); 
			for (int i = 0; i < length; i++) {     
				for (int j = i+1; j < length; j++) {     
					if(gdparray[i] < gdparray[j]) {    
						temp = gdparray[i];    
						gdparray[i] = gdparray[j];    
						gdparray[j] = temp;    
					}	     
				}     
			}  
	}
	
	//Sort the dethrate array values by using ascending Order
	void ascendingOrderdeathrateSort(struct Element elements[])
	{
		double temp = 0;   
		int length = sizeof(deathratearray)/sizeof(deathratearray[0]); 
			for (int i = 0; i < length; i++) {     
				for (int j = i+1; j < length; j++) {     
					if(deathratearray[i] > deathratearray[j]) {    
						temp = deathratearray[i];    
						deathratearray[i] = deathratearray[j];    
						deathratearray[j] = temp;    
					}	     
				}     
			}  
	}
	
	//getting the RichestCountry name by using gdp
	void getRichestCountryNameByGdp(struct Element elements[])
    {
		int value;
		double a, b;
		char *grw;
		int length = sizeof(gdparray)/sizeof(gdparray[0]);
		printf("Top Richest Countries:");
		printf("\n");
		for (int i=0; i < 5; i++) {
			a=gdparray[i];
			if(a!= 0.000000){
				for (int j = 0;  j< 12; j++) {     
					b = strtod(elements[j].gdprealgrowth, &grw);
					value=compare(a,b);
					if(value==0){
						printf("%s %lf", elements[j].country, b);
						printf("\n");
					}
				}
			}
		}
		printf("\n\n");
    }
	
	//getting the Poorest Country name by using gdp
	void getPoorestCountryNameByGdp(struct Element elements[])
    {
		int value;
		double a, b;
		char *grw;
		int length = sizeof(gdparray)/sizeof(gdparray[0]);
		printf("\n");
		printf("Top Poorest Countries:");
		printf("\n");
		for (int i=length-1; i > 5 ; i--) {
			a=gdparray[i];
			if(a!= 0.000000){
				for (int j = 0;  j< 12; j++) {     
					b = strtod(elements[j].gdprealgrowth, &grw);
					value=compare(a,b);
					if(value==0){
						printf("%s %lf", elements[j].country, b);
						printf("\n");
					}
				}
			}
		}
		printf("\n\n");
    }
	
	//getting the happiest Country name by using deathRate
	void getHappiestCountryNameByDeathRate(struct Element elements[])
    {
		int value;
		double a, b;
		char *dtr;
		int length = sizeof(deathratearray)/sizeof(deathratearray[0]);
		printf("\n");
		printf("Top Happiest Countries:");
		printf("\n");
		for (int i=0; i < 6; i++) {
			a=deathratearray[i];
			if(a!= 0.000000){
				for (int j = 0;  j< 12; j++) {     
					b = strtod(elements[j].deathrate, &dtr);
					value=compare(a,b);
					if(value==0){
						printf("%s %lf", elements[j].country, b);
						printf("\n");
					}
				}
			}
		}
		printf("\n\n");
    }
	
	//comparision logic double values
	int compare (double a, double b)
	{
		if (a > b) return 1;
		else if (a < b) return -1;
		else return 0;
		 
	}
	
