#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d* next;
}qlink;

qlink *find(qlink *head)
{
	qlink *s;
	for(head;head;head=head->next)
	{
		if(head->next=NULL)
		{
			s=head;
			return s;
		}
	}
}

qlink *build()
{
	qlink *head=(qlink *)malloc(sizeof(qlink));
	qlink *rear=(qlink *)malloc(sizeof(qlink));
	head->next=rear;head->data=NULL;
	rear->next=NULL;rear->data=NULL;
	qlink *h;
	int i;
	for(i=0;i<5;i++)
	{
		qlink *s=(qlink *)malloc(sizeof(qlink));
		s->data=i*i;
		if(i!=4)
		{
			s->next=head;
			rear->next=s;
			rear=s;
		}else 
		{
			s->next=NULL;
			rear->next=s;
			rear=s;
		}
	}
	h=head;
	head=head->next;
	free(h);
	return head;
}

qlink *insert(qlink *head)
{
	qlink *s=(qlink *)malloc(sizeof(qlink));
	s->data=888;
	s->next=head->next;
	head->next=s;
	return s;
}

qlink *del(qlink *head)
{
	qlink *h=head->next,*last,*p;
	for(p=NULL;h;p=h,h=h->next)
	{
		if(h->next=NULL)
		{
			p->next=h->next;
			last=h;
			free(last);
		}
	}
	return head;
}

void bianli(qlink *head)
{
	qlink *h=head;
	for(h;h;h=h->next)
	{
		printf("%d\n",h->data);
	}
	printf("------------------end\n");
}

int main()
{
	qlink *head=build();
	bianli(head);
	qlink *s=insert(head);
	bianli(s);
	qlink *p=del(head);
	bianli(p);
			
 } 
