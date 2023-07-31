#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	node *lefft;
	node *right;
}Btree;

Btree *build()
{
	
	int num;
	printf("please input the num:\n");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else 
	{
		Btree *bt=(Btree *)malloc(sizeof(Btree));
		bt->data=num;
		bt->lefft=build();
		bt->right=build();
		return bt;
	}
}
void PrePrint(Btree *t)
{
	if(t!=NULL)
	{
		printf("%d->",t->data);
		PrePrint(t->lefft);
		PrePrint(t->right);
	}
}




int main()
{
	Btree *t=build();
	PrePrint(t);
	
}
