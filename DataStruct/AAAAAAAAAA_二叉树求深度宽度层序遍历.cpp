#include <Stdio.h>
#include <Stdlib.h>
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

int isempty(qnode *q)
{
	return q->front==q->rear?1:0;
}
int isfull(qnode *q)
{
	return q->rear==maxsize?1:0;
}

qnode *BuildQ()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}

tree *BuildT(int a[],int &n)
{
	int num=a[n++];
	if(num==0)
	{
		return NULL;
	}else 
	{
		tree *t=(tree *)malloc(sizeof(tree));
		t->data=num;
		t->left=BuildT(a,n);
		t->right=BuildT(a,n);
		return t;
	}
}
void Printree(tree *t)
{
	if(t!=NULL)
	{
		Printree(t->left);
		printf("%d->",t->data);
		Printree(t->right);
	}
}
int Deep(tree *s)
{
	int DL=0,DR=0;       //这里要初始化啊！！！！！！ 
	tree *t=s;
	if(t==NULL)
	{
		return NULL;
	}else
	 {
		if(t->left!=NULL)
		{
			DL=Deep(t->left);
		}
		if(t->right!=NULL)
		{
			DR=Deep(t->right);
		}
		return (DL>DR?DL:DR)+1;
	 }
}
void push(tree *s,qnode *q)
{
	if(isfull(q))
	{
		printf("the queue is full!\n");
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

void LayerS(tree *t,qnode *q)
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
int Width(tree *t)
{
	int i,j,front,rear;
	int max=0;
	front=rear=0;
	tree *q[maxsize];
	if(t!=NULL)
	{
		rear++;
		q[rear]=t;
		while(rear!=front)
		{
			int len=rear-front;
			if(max<len)
			{
				max=len;
			}	
			for(i=0;i<len;i++)
			{
				tree *p=q[++front];
				if(p->left!=NULL)
				{
					q[++rear]=p->left;
				}
				if(p->right!=NULL)
				{
					q[++rear]=p->right;
				}
			}	
		}
		return max;
	}else 
	{
		return 0;
	}
}

int main()
{
	qnode *q=BuildQ();	
	int a[]={1,2,4,0,0,5,0,0,3,6,0,0,7,0,0};
	//	int a[]={1,2,3,0,0,4,5,0,0,6,0,0,7,0,0,};

	int n=0;
	tree *t=BuildT(a,n);
	Printree(t);
	printf("\n");
	int D=Deep(t);
	printf("the deep is %d\n",D);
	LayerS(t,q);
	int wid=Width(t);
	printf("the width is %d\n",wid);
}





