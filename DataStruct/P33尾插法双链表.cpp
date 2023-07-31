#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *front;
	struct d *next;
}dlink;
dlink *DEL(dlink *head,int pos);
dlink *insert(dlink *head,int x,int pos);
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
	printf("-----------------end\n");
}

dlink *insert(dlink *head,int x,int pos)
{
	dlink *h,*p,*s;
	int i=1;
	for(h=head,p=NULL,i;h;p=h,h=h->next,i++)
	{
		if(pos==1)
		{
			s=(dlink *)malloc(sizeof(dlink));
			s->next=h->next;
			s->front=NULL;
			s->data=x;
			return s;
		}
		if(i==pos)
		{
			if(p)
			{
				s=(dlink*)malloc(sizeof(dlink));
				s->data=x;s->next=h->next;
				s->front=p;
				p->next=s;
				h->front=s;
			}else
			{
				head=h->next;
			}
		}
	}
	return head;
}
dlink *DEL(dlink *head,int pos)
{
	dlink *q,*p,*h;
	int i=0;
	for(h=head,q=NULL;h;q=h,h=h->next,i++)
	{
		if(i==pos)
		{
			if(q)
			{
				q->next=h->next;
				h->next->front=q;
				free(h);
				break;
			}else
			{
				head=h->next;
			}
		}
	}
	return head;
}


int main()
{
	dlink *head=build();
	bianli(head->next);
	dlink *ins,*del;
	int x=888;int pos=1; int poss=5;
	ins=insert(head,x,pos);
	bianli(ins);
	del=DEL(ins,poss);
	bianli(del);
 } 
