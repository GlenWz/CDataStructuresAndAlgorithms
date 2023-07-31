#include <stdio.h>
#include <stdlib.h>
#define maxsize 20
typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

typedef struct n{
	int data[maxsize];
	int length;
}stack;

tree * build()
{
	int n;
	tree *s=(tree *)malloc(sizeof(tree));
	printf("please input the value!");
	scanf("%d",&n);
	if(n==0)
	{
		return NULL;
	}
	else
	{
		s->left=build();
		s->right=build();
		return s;
	}
}

tree *Stack(tree *head,)
{
	tree *t;
	t=head;
	stack *s1=(stack *)malloc(sizeof(stack));
	while(t||length!=maxsize)
	{
		while(t)
		{
			push(s1,t);
			t=t->left;
		}
	}
	
}

void push(stack s1,tree *t)
{
	
}

int main()
{
	tree *head;
	head=build();
	tree *stack;
	stack=Stack(head);
}
