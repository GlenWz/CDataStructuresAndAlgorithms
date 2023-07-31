#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100

typedef struct tree{
	int data;
	struct tree *left,*right;
}btree;

typedef struct qnode{
	btree *data[MAXSIZE];
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

btree *buildtree()
{
	int num;
	printf("please input the num:\n");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else 
	{
		btree *t=(btree *)malloc(sizeof(btree));
		t->data=num;
		t->left=buildtree();
		t->right=buildtree();
	}
}

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}
int push(btree *t,qnode *q)
{
	if(isfull(q))
	{
		printf("the queue is full!\n");
		return NULL;
	}
	q->data[q->rear]=t;
	q->rear++;
}
btree *pop(qnode *q)
{
	if(isempty(q))
	{
		printf("the queue is empty!");
		return NULL;
	}
	return q->data[(q->front)++];
}

void layer(btree *t,qnode *q)
{
	btree *s=t;
	if(s!=NULL)
	{
		push(s,q);
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

void midprint(btree *t)
{
	if(t!=NULL)
	{
		midprint(t->left);
		printf("%d\t",t->data);
		midprint(t->right);
	}
}

int main()
{
	btree *t=buildtree();
	qnode *q=buildq();
	printf("ÖĞĞò±éÀúÊÇ£º\n");
	midprint(t);
	printf("\nlayer:\n");
	layer(t,q);
	
}
