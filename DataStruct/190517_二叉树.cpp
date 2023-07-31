#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define Maxsize 10
typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}Btree;

typedef struct q{
	int *data[Maxsize];
	int front,rear;
}qnode;





Btree *buildtree()
{
	int num;
	printf("please input the NUM:\n");
	scanf("%d",&num);
	if(num==-1)
	{
		return NULL;
	}else 
	{
		Btree *t=(Btree *)malloc(sizeof(Btree));
		t->data=num;
		t->left=buildtree();
		t->right=buildtree();
	}
}
void Pre(Btree *t)
{
	if(t)
	{
		printf("%d  ",t->data);
		Pre(t->left);
		Pre(t->right);
	}
}

void MID(Btree *t)
{
	if(t!=NULL)
	{
		MID(t->left);
		printf("%d  ",t->data);
		MID(t->right);
	}
}
void Lat(Btree *t)
{
	if(t!=NULL)
	{
		Lat(t->left);
		Lat(t->right);
		printf("%d  ",t->data);
	}
}




int main()
{
	Btree *t=buildtree();
	qnode *q=buildq();
	printf("Pre:");
	Pre(t);
	printf("\n");
	printf("MID:");
	MID(t);
	printf("\n");
	printf("Lat:");
	Lat(t);
	
}
