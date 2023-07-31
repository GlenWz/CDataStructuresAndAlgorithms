#include <stdio.h>
#include <Stdlib.h>

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

tree *buildt()
{
	int data;
	printf("please input the V:\n");
	scanf("%d",&data);
	if(data==0)
	{
		return NULL;
	}else 
	{
		tree *t=(tree *)malloc(sizeof(tree));
		t->data=data;
		t->left=buildt();
		t->right=buildt();
	}
}
void MID(tree *t)
{
	if(t)
	{
		MID(t->left);
		printf("%d->",t->data);
		MID(t->right);
	}
}
void Lat(tree *t)
{
	if(t)
	{
		Lat(t->left);
		Lat(t->right);
		printf("%d->",t->data);
	}
}

int main()
{
	tree *t1=buildt();
	MID(t1);
	printf("\n");
	Lat(t1);	
 } 
