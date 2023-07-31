#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *buildn()
{
	int num;
	printf("please input  the node:\n");
	scanf("%d",&num);
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
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
node *merge(node *s,node *b)
{
	node *q,*ret,*p;
	q=s;
	p=b;
	s=s->next;
	b=b->next;
	ret=q;
	free(p);
	while(s!=NULL&&b!=NULL)
	{
		if(s->data>b->data)
		{
			q->next=b;
			q=b;
			b=b->next;
		}else 
		{
			q->next=s;
			q=s;
			s=s->next;
		}
	}
	q->next=NULL;
	if(s!=NULL)
	{
		q->next=s;
	}
	if(b!=NULL)
	{
		q->next=b;
	}
	return ret;
}

void print(node *head)
{
	node *s;
	printf("\n");
	for(s=head->next;s!=NULL;s=s->next)
	{
		printf("%d->",s->data);
	}
}



int main()
{
	node *s=buildn();
	print(s);
	node *b=buildn();
	print(b);
	node *sb=merge(s,b);
	print(sb);
}
