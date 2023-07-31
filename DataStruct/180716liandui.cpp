#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}node;

typedef struct f{
	struct node *front;
	struct node *rear;
}fx;

fx *build()
{
	node *p1=(node *)malloc(sizeof(node));
	node *p2=(node *)malloc(sizeof(node));
	fx *head; p1->next=p2;p2->next=NULL;
	p1->data=555;p2->data=666;
	head->front->next=p1;
	head->rear->next=p2;
	return head;
}
void schu(fx *head)
{
	node *he=head->front;
	for(he;he;he=he->next)
	{
		printf("%d\n",he->data);
	}
}





int main()
{
	fx *head=build();
	schu(head);
//	fx *add=ADD();
	
}
