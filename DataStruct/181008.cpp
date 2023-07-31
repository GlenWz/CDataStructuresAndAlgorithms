#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct d{
	int data;
	struct d *next;
}node;

node *buildn()
{
	int num;
	printf("please input the NUMEBER:\n");
	scanf("%d",&num);
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=0;i<num;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->next=NULL;
		s->data=i*num;
		head->next=s;
		head=s;
	}
	return ret;
}

node *merge(node *s,node *t)
{
	node *q,*ret,*p,*tmp;
	q=s;
	s=s->next;
	p=t;
	t=t->next;
	free(p);
	ret=q;
	for(;s!=NULL&&t!=NULL;)
	{
		if(s->data<t->data)
		{
			q=s;
			s=s->next;
		}else if(s->data>t->data)
		{
			t=t->next;
		}else if(s->data==t->data)
		{
			tmp=s;
			q->next=s->next;
			s=s->next;
			free(tmp);
			
		}
	}
	return ret;
}
void print(node *n)
{
	node *s;
	for(s=n->next;s!=NULL;s=s->next)
	{
		printf("%d->",s->data);
	}
}

node *MERGE(node *st,node *ts)
{
	node *q,*ret,*p;
	q=st;
	p=ts;
	ret=q;
	st=st->next;
	ts=ts->next;
	free(p);
	while(st!=NULL&&ts!=NULL)
	{
		if(st->data>ts->data)
		{
			q->next=ts;
			q=ts;
			ts=ts->next;
		}else 
		{
			q->next=st;
			q=st;
			st=st->next;
		}
	}
	if(st!=NULL)
	{
		q->next=st;
	}
	if(ts!=NULL)
	{
		q->next=ts;
	}
	return ret;
}





int main()
{
	node *s=buildn();
	print(s);
	printf("\n");
	node *t=buildn();
	print(t);
	printf("\n");
	node *st=merge(s,t);
	print(st);
	printf("\n");
	node *ts=merge(t,s);
	node *sstt=MERGE(st,ts);
	printf("\n");
	print(sstt);
	
}
