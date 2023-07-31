#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#define maxsize 100

typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right;
}btree;

typedef struct {
	btree *data[maxsize];
	int front,rear;
}qnode;

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->rear=q->front=0;
	return q;
}
bool isempty(qnode *q)
{
	if(q->front==q->rear)
	{
		return 1;
	}else 
	{
		return 0;
	}
}
bool isfull(qnode *q)
{
	if(q->rear==maxsize)
	{
		return 1;
	}else 
	{
		return 0;
	}
}

btree *buildt()
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
		t->left=buildt();
		t->right=buildt();
	}
}

void push(btree *t,qnode *q)
{
	if(isfull(q))
	{
		printf("the sss is full");
	}
	q->data[q->rear]=t;
	q->rear++;
}
btree *pop(qnode *q)
{
	if(isempty(q))
	{
		printf("the queue is empty");
		return NULL;
	}
	return q->data[(q->front)++];
}

void layer(btree *s,qnode *q)
{
	btree *t=s;
	if(t!=NULL)
	{
		push(t,q);
	}
	while(!isempty(q))
	{
		t=pop(q);
		printf("%d->",t->data);
		if(t->left!=NULL)
		{
			push(t->left,q);
		}
		if(t->right!=NULL)
		{
			push(t->right,q);
		}
	}	
}

void pre(btree *t)
{
	if(t!=NULL)
	{
		printf("%d->",t->data);
		pre(t->left);
		pre(t->right);
	}
}

int main()
{
	btree *t=buildt();
	pre(t);
	qnode *q=buildq();
	printf("\n");
	layer(t,q);
}
