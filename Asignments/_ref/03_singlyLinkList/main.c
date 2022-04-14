#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

int takeData()
{
	int data;
	printf("\nEnter integer: ");
	scanf("%d", &data);
	return data;
}

int main()
{
	Node *head = NULL;
	Node *p = NULL;
	int N = 0;

	printf("How many nodes you want: "); scanf("%d", &N);

	
	head = malloc(sizeof(Node) );
	head->next = NULL;
	head->data = takeData();
	p = head;

	while(N > 1)
	{

		p->next = malloc(sizeof(Node) );
		p = p->next;
		p->next = NULL;
		p->data = takeData();
		N--;
	}


	p = head;
	while(p != NULL)
	{
		printf("[%d]->",  p->data);
		p = p->next;
	}
	printf("NULL\n");

	return 0;
}
