#include <Stdio.h>
#include <Stdlib.h>
#define Max 100
typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;
typedef struct n{
	int data[Max];
	int front,rear;
}qnode;

int POP(qnode *q)
{
	if(q->front==q->rear)
	{
		printf("the queue is NULL!\n");
		return NULL;
	}
	return q->data[q->front++];
}

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	for(int i=0;i<10;i++)
	{
		q->data[q->rear++]=i*i;
	}
	return q;
}
tree *buildt(qnode *q,tree *p)
{
	if(q->front==q->rear)
	{
		return NULL;
	}else 
	{
		
	}
}
void MID(tree *t)
{
	if(t!=NULL)
	{
		MID(t->left);
		printf("%d\t",t->data);
		MID(t->right);
	}
}

int main()
{
	qnode *q=buildq();
	tree *p;
	tree *t=buildt(q,p);
	MID(t);
}
