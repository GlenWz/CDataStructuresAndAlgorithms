#include <Stdio.h>
#include <Stdlib.h>
#include <Stdbool.h>

typedef struct d{
	int data;
	struct d* next;
}node;

node *buildn()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	int n;
	printf("please input the node's number:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*i+n;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *merge(node *m,node *n)
{
	node *q,*ret,*s;
	q=n;
	n=n->next;
	s=m;
	ret=s;
	m=m->next;
	free(q);
	while(m!=NULL&&n!=NULL)
	{
		if(m->data>=n->data)
		{
			s->next=n;
			n=n->next;
			s=s->next;
		}else 
		{
			s->next=m;
			m=m->next;
			s=s->next;
		}
	}
	if(m!=NULL)
	{
		s->next=m;
	}
	if(n!=NULL)
	{
		s->next=n;
	}
	return ret;
}
void print(node *s)
{
	for(node *a=s->next;a!=NULL;a=a->next)
	{
		printf("%d->",a->data);
	}
}

int main()
{
	node *n=buildn();
	node *m=buildn();
	node *mn=merge(m,n);
	print(mn);
}
