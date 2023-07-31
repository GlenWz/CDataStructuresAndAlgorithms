#include <Stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *buildn()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	int num;
	printf("please input the value:\n");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		if(i==5)
		{
			s->data=1;
		}else 
		{
			s->data=i+num;
		}
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
void delmin(node *s)
{
	node *min,*p,*q,*minp;
	p=s;
	q=s->next;
	int mint=q->data;
	for(;q!=NULL;p=q,q=q->next)
	{
		if(q->data<mint)
		{
			minp=p;
			min=q;
		}
	}
	if(minp==NULL&&min==NULL)
	{
		printf("error!\n");
	}
	minp->next=min->next;
	minp=min;
	free(minp);
}
void print(node *s)
{
	node *n;
	for(n=s->next;n!=NULL;n=n->next)
	{
		printf("%d->",n->data);
	}
	printf("\n");
}


int main()
{
	node *n=buildn();
	print(n);
	delmin(n);
	print(n);
}
