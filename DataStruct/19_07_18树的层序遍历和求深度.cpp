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

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}
tree *buildt(int a[],int &n,int len)
{
	if(a[n]==0)
	{
		n++;
		return NULL;
	}else 
	{
		tree *t=(tree *)malloc(sizeof(tree));
		t->data=a[n++];
		t->left=buildt(a,n,len);
		t->right=buildt(a,n,len);	
	}
}
int isempty(qnode *q)
{
	return q->front==q->rear?1:0;
}

int push(tree *s,qnode *q)
{
	if(q->rear==maxsize)
	{
		printf("the queue is full!\n");
		return NULL;
	}
	q->data[q->rear++]=s;
}
tree *pop(qnode *q)
{
	if(isempty(q))
	{
		printf("the queue is empty!\n");
		return NULL;
	}
	return q->data[q->front++];
}

void Layer(tree *t,qnode *q)
{
	tree *s=t;
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
int Deep(tree *t)
{
	int DL,DR;
	if(t==NULL)
	{
		return NULL;
	}
	while(t!=NULL)
	{
		DL=Deep(t->left);
		DR=Deep(t->right);
		return ((DL>DR)?DL:DR)+1;
	}
}
void PrintT(tree *t)
{
	if(t!=NULL)
	{
		PrintT(t->left);
		printf("%d->",t->data);
		PrintT(t->right);
	}
}
int main()
{
	qnode *q=buildq();
	int a[]={1,2,4,0,0,5,0,0,3,0,0,};
//	int a[]={1,2,3,4,0,0,5,0,0,6,0,0,7,0,0,};
	int n=0;
	int len=sizeof(a)/sizeof(a[0]);
	tree *t=buildt(a,n,len);
	Layer(t,q);
	int deel=Deep(t);
	printf("the deep is %d\n",deel);
	PrintT(t);
}













