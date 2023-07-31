#include <Stdio.h>
#include <Stdlib.h>
#define MAXSIZE 8

typedef struct node{
	int data;
	struct node *next;
}node;

node *buildn()
{
	int num;
	printf("please in[ut the num:\n");
	scanf("%d",&num);
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=0;i<num;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->next=NULL;
		head->next=s;
		head=s;
		if(i%3==0)
		{
			s->data=(i-1)*(i-1);
		}else 
		{
			s->data=i*i;
		}
	}
	return ret;
}
void printlink(node *s)
{
	printf("\n");
	for(node *a=s->next;a!=NULL;a=a->next)
	{
		printf("%d->",a->data);
	}
}
void dele(node *s)
{
	node *p,*q;
	p=s;
	q=s->next;
	for(;q!=NULL;p=q,q=q->next)
	{
		if(p->data==q->data)
		{
			node *d=q;
			q=q->next;
			p->next=q;
			free(d);
		}
	}
}




int main()
{
	node *n=buildn();
	printlink(n);
	dele(n);
	printlink(n);
	
}
