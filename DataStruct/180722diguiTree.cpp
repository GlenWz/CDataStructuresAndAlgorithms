#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

tree *build()
{
	int x;
	printf("please input the value");
	scanf("%d",&x);
	if(x==0)
	{
		return NULL;
	}
	else
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=x;
		s->left=build();
		s->right=build();
		return s;
	}
}

void pre(tree *head)
{
	if(head)
	{
	printf("%d\n",head->data);
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
	mid(head);
	last(head);
}
