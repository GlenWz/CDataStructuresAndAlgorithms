#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

tree *build()
{
	int num;
	printf("please input the number, and xxx:");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}
	else 
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=num;
		s->left=build();
		s->right=build();
		return s;
	}
}
void Pre(tree *head)
{
	if(head)
	{
		printf("pre=%d\n",head->data);
		Pre(head->left);
		Pre(head->right);
	}
}

void MID(tree *head)
{
	if(head)
	{
		MID(head->left);
		printf("MID=%d\n",head->data);
		MID(head->right);
	}
}
void LAST(tree *head)
{
	if(head)
	{
		LAST(head->left);
		LAST(head->right);
		printf("last:%d\n",head->data);
	}
}


int main()
{
	tree *head;
	head=build();
	Pre(head);
	MID(head);
	LAST(head);
		
}
