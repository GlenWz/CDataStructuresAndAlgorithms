#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100

typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right;
}tree;

typedef struct qnode{
	tree *data[MAXSIZE];
	int front,rear;
}qnode;

bool isfull(qnode *q)
{
	return q->rear==MAXSIZE;
}
bool isempty(qnode *q)
{
	return q->front==q->rear;
}

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}

tree *buildt()
{
	int num;
	printf("please input the tree :\n");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else 
	{
		tree *t=(tree *)malloc(sizeof(tree));
		t->data=num;
		t->left=buildt();
		t->right=buildt();
	}
}
void preprint(tree *t)
{
	if(t!=NULL)
	{
		preprint(t->left);
		printf("%d->",t->data);
		preprint(t->right);
	}
}
int push(tree *t,qnode *q)
{
	if(isfull(q))
	{
		return NULL;
	}
	q->data[q->rear]=t;
	q->rear++;
}
tree * pop(qnode *q)
{
	if(isempty(q))
	{
		printf("the queue is fempty!");
		return NULL;
	}
	return q->data[(q->front)++];
}

int layer(tree *t,qnode *q)
{
	tree *s;
	if(t!=NULL)
	{
		push(t,q);
	}else 
	{
		printf("the tree is NNULL!");
		return NULL;
	}
	while(!isempty(q))
	{
		s=pop(q);
		printf("%d->",s->data);
		if(s->left!=NULL)
		{
			push(s->left,q);
		}
		if(s->right!=NULL)
		{
			push(s->right,q);
		}
	}
}


int main()
{
	qnode *q=buildq();
	tree *t=buildt();
	preprint(t);
	printf("\n");
	layer(t,q);
	return 0;
}
