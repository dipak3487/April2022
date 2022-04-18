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

int printList(Node *head)
{
	Node *p;
	p = head;
	while(p != NULL)
	{
		printf("[%d]->",  p->data);
		p = p->next;
	}
	printf("NULL\n");

	return 0;
}

int main()
{
	Node *head = NULL;
	Node *p = NULL;
	Node *newNode = NULL;
	int N = 0, total=0;

	printf("How many nodes you want: "); scanf("%d", &N);
	total = N;
	
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


	printList(head);



	printf("Where you want to insert new node: [0-%d]", total);
	scanf("%d", &N);
	newNode = malloc(sizeof(Node));
	newNode->next = NULL;
	takeData(newNode);

	p = head;
	while(N > 1)
	{
		p=p->next;
		N--;
	}

	if(N)	//if not zero'th gap
	{
		newNode->next = p->next;
		p->next = newNode;
	}
	else	// if zero'th gap
	{
		newNode->next = head;
		head = newNode;
	}

	printList(head);

	printf("After removing head, the list looks like: \n");

	p = head;
	head = head->next;
	p->next = NULL;
	free(p);
	p = NULL;

	printList(head);

	return 0;
}
