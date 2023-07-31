#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *front;
	struct d *next;
}dlink;

dlink *build()
{
	dlink *head=(dlink*)malloc(sizeof(dlink));
	dlink *rear=(dlink*)malloc(sizeof(dlink));
	head->front=rear;head->next=rear;head->data=NULL;
	rear->next=head;rear->front=head;rear->data=NULL;
	int num;
	printf("how many dlink doU want?");
	scanf("%d",&num); 
	int x=2;
	for(int i=0;i<num;i++,x+=3)
	{
		dlink *s=(dlink*)malloc(sizeof(dlink));
		s->next=head;s->front=rear;s->data=x;
		head->front=s;rear->next=s;
		rear=s;
	}
	rear->next=NULL;
	return head->next;
}
void bianli(dlink *head)
{
	dlink *h;
	for(h=head;h;h=h->next)
	{
		printf("%d\n",h->data);
	}
}

int main()
{
	dlink *head=build();
	bianli(head->next);
 } 
