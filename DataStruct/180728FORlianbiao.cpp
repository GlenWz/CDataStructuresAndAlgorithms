#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *build()
{
	link *head,*rear;
	head->next=rear;
	rear->next=head;
	int x;
	printf("how many link do you want to build");
	scanf("%d",&x);
	for(int i=0;i<x;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->next=rear;
		head->next=s;
		rear=s;
	}
	return head;
}
void *bianli(link *head)
{
	link *h=head;
	for(h;h;h=h->next)
	{
		printf("%d\n",h->data);
	}
}

int main()
{
	link *head=build();
	bianli(head);
}
