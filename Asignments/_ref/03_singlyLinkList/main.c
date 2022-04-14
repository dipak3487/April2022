#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

void takeData(Node *p)
{
	printf("\nEnter integer: ");
	scanf("%d", &(p->data) );
	return;
}

int main()
{
	Node *head = NULL;
	Node *p = NULL;
	int N = 0;

	printf("How many nodes you want: "); scanf("%d", &N);

	
	head = malloc(sizeof(Node) );
	head->next = NULL;
	takeData(head);
	p = head;

	while(N > 1)
	{

		p->next = malloc(sizeof(Node) );
		p = p->next;
		p->next = NULL;
		takeData(p);
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
