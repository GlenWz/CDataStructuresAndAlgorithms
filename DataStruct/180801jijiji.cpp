#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *build()
{
	link *head,*rear;
	head=(link *)malloc(sizeof(link));
	rear=(link *)malloc(sizeof(link));
	head->next=rear; head->data=NULL;
	rear->next=head; rear->data=NULL;
	int x=2;
	int num; printf("num");
	scanf("%d",&num);
	for(int i=0;i<num;i++,x+=3)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=x;
		s->next=head;
		rear->next=s;
		rear=s;
	}
	return head->next;
}
link *del(link *head)
{
	link *p,*q,*r;
	link *B=(link *)malloc(sizeof(link));
	B->next=NULL;
	r=B;
	p=head;
	while(p->next!=NULL)
	{
		if(p->next->data%2==0)
		{
			q=p->next;
			p->next=q->next;
			q->next=NULL;
			r->next=q;
			r=q;
		}else
		{
			p=p->next;
		}
	}
	return B;
}
void print(link *head)
{
	link *h;
	for(h=head;h->data;h=h->next)
	{
		printf("%d\n",h->data);
	}
	printf("%d\n");
}

int main()
{
	link *h=build();
	print(h->next);
	//link *s=(link *)malloc(sizeof(link));
	link *s=del(h);
	print(s->next); 
}
