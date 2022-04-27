/*
        1) view all contacts.
        2) add a contact.
        3) remove a contact.
        4) search details of any contact number.
        5) update details of any contact.
        6) delete selected contact from  phonebook.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct person
{
    char name[30];
    char address[40];
    long int mble_no;
    char mail[100];
};

// Defining person data type.
typedef struct person person;

// All function declaration.
void print_menu();
void add_person();
void list_record();
void search_person();
void remove_person();
void update_person();
void take_input(person *p);


// Program starts here.
int main()
{
    start();
    return 0;
}

// This function will start our program.
int start()
{
    int choice;
    while(1)
    {
        print_menu();
        scanf("%d",&choice);
        switch(choice)
        {
		case 1:
			list_record();
			getchar();
			getchar();
			break;
            case 2:
                add_person();
                getchar();
                getchar();
                break;
            case 3:
                search_person();
                getchar();
                getchar();
                break;
            case 4:
                remove_person();
                getchar();
                getchar();
                break;
            case 5:
                update_person();
                getchar();
                getchar();
                break;           
            default :
                system("clear");
                printf("## Thanks for using Telephone Directory visit again ## \n");
		
                getchar();
                getchar();
                exit(1);
        }
    }
}

// This will print main menu.
void print_menu()
{
    system("clear");
    printf("\t\t************************************************************************\n");
    printf("\t\t*                  Welcome TO  Telephone Directory                   *\n");
    printf("\t\t************************************************************************\n\n");
    printf("\t\t\t1) List Record\n\n");
    printf("\t\t\t2) Add User\n\n");
    printf("\t\t\t3) Search User\n\n");
    printf("\t\t\t4) Remove User\n\n");
    printf("\t\t\t5) Update User\n\n");
    printf("\t\t\t6) exit\n\n");

    printf("\t\t\t\tEnter your Choice : ");
}

// This function will add contact into phonebook.
void add_person()
{
    system("clear");
    FILE *fp;
    fp = fopen("phonebook_db", "ab+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        take_input(&p);
        fwrite(&p, sizeof(p), 1, fp);
        fflush(stdin);
        fclose(fp);
        system("clear");
        printf("Record added Successfully\n");
        printf("Press any key to continue ....\n");

    }
}

// By this we take contact information.
void take_input(person *p)
{
    system("clear");
    // This getchar is for taking \n occured by previous functions.
    // So that scanset in scanf will work properly.
    getchar();
    printf("Enter name : ");
    // Here we are using scanset '^' - >  until get
    scanf("%[^\n]s",p->name);

    printf("Enter address : ");
    scanf("%s",p->address); 
    
    printf("Enter mobile no : ");
    scanf("%ld",&p->mble_no); 
    
    printf("Enter email : ");
    scanf("%s",p->mail); 
}

// This function will list contact available in phonebook.
void list_record()
{
    system("clear");
    FILE *fp;
    fp = fopen("phonebook_db", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        printf("\n\t\t\t\t******************************************************************************\n");
        printf("\t\t\t\t*                  Here is all records listed in Telephone Directory           *\n");
        printf("\t\t\t\t******************************************************************************\n\n\n");
        printf("  NAME\t\t\t\t   ADDRESS\t\t    PHONE NO\t\t      EMAIL\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
        // fseek(fp,-(sizeof(p)*2L),2);
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            int i;
            int len1 = 40 - strlen(p.name);
            int len2 = 19 - strlen(p.address);
            int len3 = 15;
            printf("%s",p.name);
            for(i=0;i<len1;i++) printf(" ");

            printf("%s",p.address);
            for(i=0;i<len2;i++) printf(" ");

            printf("%ld",p.mble_no);
            for(i=0;i<len3;i++) printf(" ");

            printf("%s",p.mail);
            printf("\n");
            fflush(stdin);
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
        
    }
}

// This function will search contact in phonebook.
void search_person()
{
    system("clear");
   // long int phone;
    char name[30];
    printf("Enter Name of the person you want to search : ");
    scanf("%s",&name);

    FILE *fp;
    fp = fopen("phonebook_db", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
       int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if((strcmp(p.name,name )==0))
            {
                printf("  NAME\t\t\t\t   ADDRESS\t\t    PHONE NO\t\t    EMAIL\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
                int i;
               int len1 = 40 - strlen(p.name);
                int len2 = 19 - strlen(p.address);
                int len3 = 15;
               
                printf("%s",p.name);
                for(i=0;i<len1;i++) printf(" ");

                printf("%s",p.address);
                for(i=0;i<len2;i++) printf(" ");

                printf("%ld",p.mble_no);
                for(i=0;i<len3;i++) printf(" ");

                printf("%s",p.mail);
                printf("\n");

                flag = 1;
                break;
            }
            else continue;
             fflush(stdin);
        }
        if(flag == 0) 
        {
            
	system("clear");
            printf("Person is not in the Phonebook\n");
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
    }

}

// This function will remove contact from phonebook.
void remove_person()
{
    system("clear");
    long int phone;
    printf("Enter Phone number of the person you want to remove from phonebook : ");
    scanf("%ld",&phone);

    FILE *fp,*temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mble_no == phone)
            {
                system("clear");
                printf("Person removed successfully\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("clear");
            printf("No record found for %d number\n",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp","phonebook_db");
        fflush(stdin);
        printf("Press any key to continue....\n");
        
    }

}

// This function will update contact information.
void update_person()
{

    system("clear");
    long int phone;
    printf("Enter Phone number of the person you want to update details : ");
    scanf("%ld",&phone);

    FILE *fp,*temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mble_no == phone) 
            {   
                take_input(&p);
                fwrite(&p, sizeof(p), 1, temp);
                system("clear");
                printf("Data updated successfully\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("clear");
            printf("No record found for %d number\n",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp","phonebook_db");
        fflush(stdin);
        printf("Press any key to continue....\n");
    }
}


