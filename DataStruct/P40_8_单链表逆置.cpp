#include <stdio.h>
#include <Stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	int len;
}node;

node *builds()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	int num;
	printf("please in[put the NUM:\n");
	scanf("%d %d",&num,&head->len);
	for(int i=0;i<num;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*i;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *nizhi(node *s)
{
	node *old,*nnew,*rear;
	nnew=s;
	old=s->next;
	for(;rear!=NULL;)
	{
		rear=old->next;
		old->next=nnew;
		nnew=old;
		old=rear;
	}
	s->next->next=rear;
}
void print(node *s)
{
	node *q=s;
	for(q=q->next;q!=NULL;q=q->next)
	{
		printf("%d->",q->data);
	}
	printf("\n");
}




int main()
{
	node *s=builds();
	print(s);
	nizhi(s);
	print(s);
}
