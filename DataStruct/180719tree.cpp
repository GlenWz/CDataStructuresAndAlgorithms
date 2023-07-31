#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

tree *build() //我的二叉树内存申请 
{
	tree *head,*q;
	tree *t1=(tree *)malloc(sizeof(tree));
	tree *t2=(tree *)malloc(sizeof(tree));
	tree *t3=(tree *)malloc(sizeof(tree));
	tree *t4=(tree *)malloc(sizeof(tree));
	tree *t5=(tree *)malloc(sizeof(tree));
	tree *t6=(tree *)malloc(sizeof(tree));
	tree *t7=(tree *)malloc(sizeof(tree));
	tree *t8=(tree *)malloc(sizeof(tree));
	tree *t9=(tree *)malloc(sizeof(tree));
	head=t1;int i=10;
	t1->left=t2;t1->right=t3;
	t2->left=t4;t2->right=t6;
	t3->left=t7;t3->right=t9;
	t4->left=NULL;t4->right=NULL;
	t5->left=NULL;t5->right=NULL;
	t6->left=t5;t6->right=NULL;
	t7->left=NULL;t7->right=t8;
	t8->left=NULL;t8->right=NULL;
	t9->left=NULL;t9->right=NULL;
	return head;
}
void * PREH(tree *head)
{
	if(head)
	{
		printf("%d\n",head->data);
		PREH(head->left);
		PREH(head->right);
	}
}





int main()
{
	tree *head,*preh,*pr;
	head=build();
	PREH(head);
	
}
