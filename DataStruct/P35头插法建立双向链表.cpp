#include <stdio.h>
#include <Stdlib.h>


typedef struct node{
	int data;
	struct node *next;
	struct node *prior;
}node;

node *buildd()
{
	node *head=(node *)malloc(sizeof(node));
	head->prior=NULL;
	head->data=NULL;
	node *ret=head;
	int num;
	printf("please input the num:\n");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*num;
		s->next=NULL;
		s->prior=head;
		head->next=s;
		head=s;
	}
	return ret;
}
void print(node *s)
{
	for(s=s->next;s!=NULL;s=s->next)
	{
		printf("%d->",s->data);
	}
}


int main()
{
	node *n=buildd();
	print(n);
 } 
