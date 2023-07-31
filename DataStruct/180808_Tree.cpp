#include <Stdio.h>
#include <stdlib.h>
typedef struct d{
	int  data;
	struct d *lefft;
	struct d *right;
}tree;

tree *build()
{
	int num;
	printf("please input!");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else 
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=num;
		s->lefft=build();
		s->right=build();
	}
}

void pre(tree *head)
{
	if(head)
	{
		printf("%d\t",head->data);
		pre(head->lefft);
		pre(head->right);
	}
}

void mid(tree *head)
{
	if(head)
	{
		mid(head->lefft);
		printf("%d\t",head->data);
		mid(head->right);
	}
}

void last(tree *head)
{
	if(head)
	{
		last(head->lefft);
		last(head->right);
		printf("%d\t",head->data);
	}
}

int main()
{
	tree *T1=build();
	pre(T1);
	printf("\n-------------------------end\n");
	mid(T1);
	printf("\n-------------------------end\n");
	last(T1);
	printf("\n-------------------------end\n");
	int result;
}
