#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

tree *build()
{
	int n;
	printf("please input the value");
	scanf("%d",&n);
	if(n==0)
	{
		return NULL;
	}else
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=n;
		s->left=build();
		s->right=build();
		return s;
	}
}

void pre(tree *head)
{
	if(head)
	{
		printf("pre=%d\n",head->data);
		pre(head->left);
		pre(head->right);
	}
}

void mid(tree *head)
{
	if(head)
	{
		mid(head->left);
		printf("mid=%d\n",head->data);
		mid(head->right);
	}
}

void last(tree *head)
{
	if(head)
	{
		last(head->left);
		last(head->right);
		printf("last=%d\n",head->data);
	}
}

int main()
{
	tree *head;
	head=build();
	pre(head);
	printf("--------------------------end\n");
	mid(head);
	printf("--------------------end\n");
	last(head);
	printf("--------------------end\n");
}

