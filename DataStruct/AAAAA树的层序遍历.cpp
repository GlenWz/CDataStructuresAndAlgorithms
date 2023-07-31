#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#define maxsize 100

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

typedef struct {
	tree *data[maxsize];
	int front,rear;
}qnode;

tree *buildT(int a[],int &i)
{
	int num=a[i++];
	if(num==0)
	{
		return NULL;
	}else 
	{
		tree *t=(tree *)malloc(sizeof(tree));
		t->data=num;
		t->left=buildT(a,i);
		t->right=buildT(a,i);
		return t;
	}
}
tree *PrePrint(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}else 
	{
		PrePrint(t->left);
		printf("%d->",t->data);
		PrePrint(t->right);
	}
}
qnode *buildQ()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}
int isfull(qnode *q)
{
	return q->rear==maxsize?1:0;
}
int isempty(qnode *q)
{
	return q->front==q->rear?1:0;
}
void push(qnode *q,tree *t)
{
	if(isfull(q))
	{
		printf("the queue is full:\n");
	}
	q->data[q->rear++]=t;
}
tree *pop(qnode *q)
{
	if(isempty(q))
	{
		printf("the queue is empty!\n");
	}
	return q->data[q->front++];
}

void LayerPrint(tree *t,qnode *q)
{
	tree *s=t;
	if(s!=NULL)
	{
		push(q,s);
	}
	while(!isempty(q))
	{
		s=pop(q);
		printf("%d->",s->data);
		if(s->left!=NULL)
		{
			push(q,s->left);
		}
		if(s->right!=NULL)
		{
			push(q,s->right);
		}
	}
}

int main()
{
	int a[]={1,2,4,0,0,5,0,0,3,6,0,0,7,0,0};
	int len=sizeof(a)/sizeof(a[0]);
	int i=0;
	tree *t=buildT(a,i);
	PrePrint(t);
	printf("\n");
	qnode *q=buildQ();
	LayerPrint(t,q);
}
