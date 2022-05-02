#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct person
{
    char name[30];
   // char address[40];
    long int mble_no,mob;
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
int main(){
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
                search_person(); getchar();
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
    fp = fopen("info.txt", "ab+");
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

    //printf("Enter address : ");
    //scanf("%s",p->address);

    printf("Enter first mobile no : ");
    scanf("%ld",&p->mble_no); printf("Enter second mobile no : ");
    scanf("%ld",&p->mob);

    printf("Enter email : ");
    scanf("%s",p->mail);
}

// This function will list contact available in phonebook.
void list_record()
{
    system("clear");
    FILE *fp;
    fp = fopen("info.txt", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        printf("\n\t\t\t\t************************************************************************************************************\n");
        printf("\t\t\t\t*                  Here is all records listed in Telephone Directory                                   \n");
        printf("\t\t\t\t*************************************************************************************************************\n\n\n");
        printf("NAME\t\t\t\t         First Mob_NO\t\t     Second Mob_No                   EMAIL\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
 // fseek(fp,-(sizeof(p)*2L),2);
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            int i;
            int len1 = 40 - strlen(p.name);
            //int len2 = 15 - strlen(p.address);
            int len2 = 15;
            int len3 = 15;
            printf("%s",p.name);
            for(i=0;i<len1;i++) printf(" ");

            //printf("%s",p.address);
            //for(i=0;i<len2;i++) printf(" ");

            printf("%ld",p.mble_no);
            for(i=0;i<len2;i++) printf(" ");

             printf("%ld",p.mob);
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
char str[30];

    printf("Enter Name of the person you want to search : ");
   //scanf("%[^\n]s",str);
    scanf("%s",&name);

    FILE *fp;
    fp = fopen("info.txt", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
       int flag = 0,d;
        person p; while (fread(&p, sizeof(p), 1, fp) == 1)
        {

        for(d=0;d<strlen(name);d++)
//      {


    // if((((strcmp(p.name,name)==0))||((str[d]>='a')&&(str[d]<='z'))||((str[d]>='A')&&(str[d]<='Z')))||(str[d]==' '))


        if((strstr(p.name,name )!=NULL))
            {
                printf("NAME\t\t\t\t        First Mob_NO\t\t       Second Mob_No                   EMAIL\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
               int i;
               int len1 = 40 - strlen(p.name);
                //int len2 = 19 - strlen(p.address);
                int len2 = 15;
               int len3 = 15;
                printf("%s",p.name);
                for(i=0;i<len1;i++) printf(" ");

                //printf("%s",p.address);
                //for(i=0;i<len2;i++) printf(" "); printf("%ld",p.mble_no);
               for(i=0;i<len2;i++) printf(" ");

                 printf("%ld",p.mob);
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
    char name [50];
    printf("Search  Name  of the person you want to remove from phonebook : ");
    scanf("%s",&name);

    FILE *fp,*temp;
    fp = fopen("info.txt", "rb");
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
        int flag = 0,d;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
        for(d=0;d<strlen(name);d++)
          if((strcmp(p.name,name )==0))

           {
                printf("NAME\t\t\t\t        First Mob_NO\t\t       Second Mob_No                   EMAIL\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
               int i;
	 int len1 = 40 - strlen(p.name);
                //int len2 = 19 - strlen(p.address);
                int len2 = 15;
               int len3 = 15;
                printf("%s",p.name);
                for(i=0;i<len1;i++) printf(" ");

                //printf("%s",p.address);
                //for(i=0;i<len2;i++) printf(" ");
                printf("%ld",p.mble_no);
               for(i=0;i<len2;i++) printf(" ");

                 printf("%ld",p.mob);
                 for(i=0;i<len3;i++) printf(" ");


                printf("%s",p.mail);

                printf("\n");

                flag = 1;
                break;
            }
            else continue;
             fflush(stdin);
        }if(flag == 0)
        {

          system("clear");
            printf("Person is not in the Phonebook\n");
        }
//      else
  //      {
       fflush(stdin);
   //  fclose(fp);
         //printf("\n\nPress any key to continue....\n");
      //  }

   }
    printf("Enter  Name  of the person you want to remove from phonebook : ");
    scanf("%s",&name);

   // FILE *fp,*temp;
     fp = fopen("info.txt", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {

        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
     }
     else
     {
        person p; int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
         if((strcmp(p.name,name )==0))
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
            printf("No record found for %s name\n",name);
        }
        fclose(fp);
        fclose(temp);
        remove("info.txt");
        rename("temp","info.txt");
        fflush(stdin);
        printf("Press any key to continue....\n");

    }

}


// This function will update contact information.
void update_person()
{ system("clear");
    char name[50];
    printf("Enter Name of the person you want to update details : ");
    scanf("%s",&name);

    FILE *fp,*temp;
    fp = fopen("info.txt", "rb");
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
            if((strcmp(p.name,name )==0))
            {
                take_input(&p);
                fwrite(&p, sizeof(p), 1, temp);
                system("clear");
                printf("Data updated successfully\n");
                flag = 1;  }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("clear");
            printf("No record found for %s name\n",name);
        }
        fclose(fp);
        fclose(temp);
        remove("info.txt");
        rename("temp","info.txt");
        fflush(stdin);
        printf("Press any key to continue....\n");
    }
}

