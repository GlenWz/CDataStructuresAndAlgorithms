#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxsize 100
typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right;
}btree;

typedef struct {
	int front,rear;
	btree *data[maxsize];
}qnode;

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
void inqueue(qnode *q,btree *t)
{
	if(isfull(q))
	{
		printf("the queue is full!");
	}else 
	{
		q->data[q->rear]=t;
		++q->rear;	
	}
}

btree *delqueue(qnode *q)
{
	if(isempty(q))
	{
		return NULL;
	}else 
	{
		return q->data[(q->front)++];
	}
}
qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=0;q->rear=0;
	return q;
}

btree *build()
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
		t->left=build();
		t->right=build();
	}
}
void midprint(btree *t)
{
	if(t!=NULL)
	{
		midprint(t->left);
		printf("%d->",t->data);
		midprint(t->right);
	}
}
void layer(btree *t,qnode *q)
{
	btree *p;
	p=t;
	if(p!=NULL)
	{
		inqueue(q,p);
	}
	while(!isempty(q))
	{
	//	printf("i am your father!");
		p=delqueue(q);
		printf(" %d->",p->data);
		if(p->left!=NULL)
		{
			inqueue(q,p->left);
		}
		if(p->right!=NULL)
		{
			inqueue(q,p->right);
		}
	}
	printf("\n");
}

int main()
{
	btree *t=build();
	qnode *q=buildq();
	midprint(t);
	printf("\n");
	layer(t,q);
}
