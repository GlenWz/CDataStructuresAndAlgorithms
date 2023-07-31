#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *build()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	int num;
	printf("please input the NUM:\n");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*num;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}

int findnode(node *s,int v)
{
	int ret=-1;
	node *p;
	p=s;
	for(s=s->next,p;s!=NULL;p=s,s=s->next){
		if(s->data==v)
		{
			p->next=s->next;
			p=s;
			s=s->next;
			free(p);
			ret=1;
			return ret;
		}
	}
	return ret;
}
void print(node *h)
{
	node *s;
	for(s=h->next;s!=NULL;s=s->next)
	{
		printf("%d->",s->data); 
	}
	
}

int main()
{
	node *n=build();
	int num=findnode(n,15);	
	printf("the num==%d\n",num);
	print(n);
}
