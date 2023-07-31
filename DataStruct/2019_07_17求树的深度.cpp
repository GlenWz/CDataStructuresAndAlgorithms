#include <Stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;
typedef struct n{
	int data[maxsize];
	int front,rear;
}qnode;

typedef struct s{
	tree *data[maxsize];
	int rear,front;
}qtree;

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	int a[]={1,2,4,-1,-1,5,-1,-1,3,-1,-1,};
	int len=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<len;i++)
	{
		q->data[q->rear++]=a[i];
	}
	return q;
}
tree *buildt(qnode *q)
{
	int num=q->data[q->front++];
	if(num==-1)
	{
		return NULL;
	}else 
	{
		tree *t=(tree *)malloc(sizeof(tree));
		t->data=num;
		t->left=buildt(q);
		t->right=buildt(q);
		return t;
	}
}
int Deep(tree *t)
{
	int DL,DR;
	if(t==NULL)
	{
		return 0;
	}else 
	{
		DL=Deep(t->left);
		DR=Deep(t->right);
		return (DL>DR?DL:DR)+1;
	}
}
qtree *buildqt()
{
	qtree *qt=(qtree *)malloc(sizeof(qtree));
	qt->rear=qt->front=0;
	return qt;
}
int isempty(qtree *qt)
{
	return qt->front==qt->rear?1:0;
}
int PUSH(tree *s,qtree *qt)
{
	if(qt->rear==maxsize)
	{
		printf("the qt is full1\n");
		return NULL;
	}
	qt->data[qt->rear++]=s;
	
}
tree* POP(qtree *qt)
{
	if(isempty(qt))
	{
		printf("the qt is empty!\n");
		return NULL;
	}
	return qt->data[qt->front++];
}



int Layer(qtree *qt,tree *t)
{
	tree *s=t;
	if(t!=NULL)
	{
		PUSH(s,qt);
	}
	while(!isempty(qt))
	{
		s=POP(qt);
		printf("%d->",s->data);
		if(s->left!=NULL)
		{
			PUSH(s->left,qt);
		}
		if(s->right!=NULL)
		{
			PUSH(s->right,qt);
		}
	}
	return 0;
}

int main()
{
	qnode *q=buildq();
	tree *t=buildt(q);
	int deep=Deep(t);
	printf("%d\n",deep);
	qtree *qt=buildqt();
	Layer(qt,t);
}







