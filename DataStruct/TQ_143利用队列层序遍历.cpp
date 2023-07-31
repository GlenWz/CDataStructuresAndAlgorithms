#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 100

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

typedef struct n{
	tree *data[maxsize];
	int front,rear;
}qnode;

typedef struct s{
	int data[maxsize];
	int tip,jip;
}Ary;

tree *BuildTree(Ary *a)
{
	int num=a->data[a->tip++];
	if(num==0)
	{
		return NULL;
	}else 
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=num;
		s->left=BuildTree(a);
		s->right=BuildTree(a);
	}
}
qnode *BuildQ()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
}
int isempty(qnode *q)
{
	return q->front==q->rear?1:0;
}
tree *Push(tree *t,qnode *q)
{
	if(q->rear==maxsize)
	{
		printf("the queue is full!\n");
	}
	q->data[q->rear++]=t;
}
tree *Pop(qnode *q)
{
	if(isempty(q))
	{
		printf("the queue is empty!\n");
		return NULL;
	}
	return q->data[q->front++];
}

int Layer(qnode *q,tree *t)
{
	tree *s=t;
	if(t!=NULL)
	{
		Push(t,q);
	}
	while(!isempty(q))
	{
		t=Pop(q);
		printf("%d->",t->data);
		if(t->left!=NULL)
		{
			Layer(q,t->left);
		}
		if(t->right!=NULL)
		{
			Layer(q,t->right);
		}
	}
}
Ary *buildAry()
{
	Ary *a=(Ary *)malloc(sizeof(Ary));
	int A[]={1,3,7,0,0,9,0,0,5,0,0,};
	a->tip=a->jip=0;
	for(int i=0;i<sizeof(A)/sizeof(A[0]);i++)
	{
		a->data[a->jip++]=A[i];
	}
	return a;
}
int main()
{
	Ary *A=buildAry();
	tree *T=BuildTree(A);
	qnode *q=BuildQ();
	Layer(q,T);
}
