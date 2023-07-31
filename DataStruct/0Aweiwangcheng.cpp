#include <Stdio.h>
#include <stdlib.h>
#define maxsize 50

typedef struct d{
	int data;
	struct d* left;
	struct d* right;
}tree;

typedef struct n{
	int da[maxsize];
	int length;
}qlink;


tree *build()
{
	int num;
	printf("please input the value");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}
	else
	{
		tree s=(tree *)malloc(sizeof(tree));
		s->data=num;
		s->left=build();
		s->right=build();
		return s;
	}
}
void MID(tree *head)
{
	tree *t=head; int i=0;
	qlink *s=(qlink *)malloc(szieof(qlink));
	while(t||s->length==maxsize-1)
	{
		while(t)
		{
			push(s,t,i);
		}
	}
}

void push(qlink *s,tree *t,int i)
{
	s->da[i]=t->data;
	i++;
	
}

int main()
{
	tree *head;
	head=build();
	pre(head);
}
