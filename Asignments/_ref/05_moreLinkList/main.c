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

int swapNodes(Node *q, Node *p)
{
	q->next = p->next;
	q = q->next;
	p->next = q->next;
	q->next = p;
	return 0;
}

int sortList(Node *head)
{
	Node *p;
	Node *q;
	p = head;
	q = head;
	p = p->next;
	while(p != NULL && p->next != NULL)
	{
		if(p->data > p->next->data)
		{
			//swap
			swapNodes(q, p);
		}
		q = p;
		p = p->next;
	}

	return 0;
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
	Node *q = NULL;
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

	for(int i=0; i< total; i++)
	{
		p = head;
		q = head;
		p = p->next;
		if(q->data > p-> data)
		{
			head = p;
			q->next = p->next;
			p->next = q;

		}

		sortList(head);
		printList(head);
	}



	return 0;
}
