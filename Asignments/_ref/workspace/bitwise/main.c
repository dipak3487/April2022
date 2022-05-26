#include <stdlib.h>
#include<stdio.h>
#include <string.h>

typedef struct node {
	char empID[10];
	char name[100];
	char contact[14];
	char pin[7];
	char bg[3];
	char age[4];
	node *next;
} node;

node *head;

int insertValue(node *p, int index, char *value)
{
	switch(index)
	{
		case 1: //ID
			break;
		case 2:	//Name
			strncpy
			break;
	}
}

int readDB(const char *dbPath)
{

	FILE *fp = NULL;
	char record[200];
	char *str1, *token, *saveptr1;
	int j;

	fp = fopen(dbPath, "r");

	if(NULL == fp)
	{
		perror("Unable to open the file: 'emploees.db'\n");
		exit(EXIT_FAILURE);
	}


	if(NULL != fgets(record, 200, fp))
	{
		puts(record);
		head = malloc(sizeof(node));
		head->next = NULL;
		
		   for (j = 1, str1 = record; ; j++, str1 = NULL) {
			   token = strtok_r(str1, ",", &saveptr1);
			   if (token == NULL)
				   break;
			   printf("%d: %s\n", j, token);
			   insertValue(head, j, token);

		   }
	}

	p = head;

	while(NULL != fgets(record, 200, fp))
	{
		puts(record);
		p->next = malloc(sizeof(node));
		p = p->next;
		p->next = NULL;
		
		   for (j = 1, str1 = record; ; j++, str1 = NULL) {
			   token = strtok_r(str1, ",", &saveptr1);
			   if (token == NULL)
				   break;
			   printf("%d: %s\n", j, token);
			   insertValue(p, j, token);
		   }
	}

	fclose(fp);

	return 0;
}

int main(int argc, char *argv[])
{

	readDB("emploees.db");
	printRecords();


	exit(EXIT_SUCCESS);
}
