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
	printf("please input the va");
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

void PRE(tree *head)
{
	if(head)
	{
		printf("%d\n",head->data);
		PRE(head->left);
		PRE(head->right);
	}
}
void MID(tree *head)
{
	if(head)
	{
		MID(head->left);
		printf("PRE=%d\n",head->data);
		MID(head->right);
	}
}



int main()
{
	tree *head=build();
	MID(head);
	PRE(head);
}
