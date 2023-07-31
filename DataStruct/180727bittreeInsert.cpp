#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *left;
	struct d* right;
}tree;

tree *build()
{
	int num;
	printf("please input the value!");
	scanf("%d",&num);
	if(num==-1)
	{
		return NULL;
	}else
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=num;
		s->left=build();
		s->right=build();
		return s;
	}
}

tree *insert(tree *h,int x)
{
	tree *parent;
	tree *head=h;
	tree *s=(tree *)malloc(sizeof(tree));
	s->data=x;
	s->left=s->right=NULL;
	while(head)
	{
		parent=head;
		if(x<head->data)
		{
			head=head->left;
		}else
		{
			head=head->right;
		}
	}
	if(x<parent->data)
	{
		parent->left=s;
	}else
	{
		parent->right=s;
	}
	return h;
}

void mid(tree *head)
{
	if(head)
	{
		mid(head->left);
		printf("MID=%d\n",head->data);
		mid(head->right);
	}
	
}


int main()
{
	tree *head=build();
	mid(head);
	tree *ins; int x=23;
	printf("--------------------end\n");
	ins=insert(head,x);
	mid(ins);
		
}
