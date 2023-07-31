#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d* left;
	struct d* right;
}tree;

tree *build()
{
	int num;
	printf("please input the number!");
	scanf("%d",&num);
	if(num==0)
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

void pre(tree *head)
{
	if(head)
	{
		printf("pre=%d\n",head->data);
		pre(head->left);
		
		pre(head->right);
	}
}
void Inorder(tree *head)
{
	if(head)
	{
		Inorder(head->left);
		printf("I=%d\t",head->data);
		Inorder(head->right);
	}
}

void Last(tree *head)
{
	if(head)
	{
		Last(head->left);
		Last(head->right);
		printf("L=%d\t",head->data);
	}
}

int main()
{
	tree *head;
	head=build();
	pre(head);
	Inorder(head);
	printf("--------------------------------end\n");
	Last(head);
	printf("--------------------------------end\n");
	return 0;
}
