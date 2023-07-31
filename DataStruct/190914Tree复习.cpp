#include <Stdio.h>
#include <stdlib.h>
#define max 100

typedef struct d{
	int data;
	struct d *left,*right;
}tree;

tree *buildt(int a[],int &n)
{
	int num=a[n];
	n++;
	if(num==0)
	{
		return NULL;
	}else 
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=num;
		s->left=buildt(a,n);
		s->right=buildt(a,n);
		return s;
	}
}
int PreT(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	printf("%d->",t->data);
	PreT(t->left);
	PreT(t->right);
}
int MidT(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	MidT(t->left);
	printf("%d->",t->data);
	MidT(t->right);
}
int LatT(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	LatT(t->left);
	LatT(t->right);
	printf("%d->",t->data);
}
int Layer(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	tree *queue[max];
	int front=0,rear=0;
	tree *s=t;
	queue[rear++]=s;
	while(front!=rear)
	{
		s=queue[front++];
		printf("%d->",s->data);
		if(s->left!=NULL)
		{
			queue[rear++]=s->left;
		}
		if(s->right!=NULL)
		{
			queue[rear++]=s->right;
		}
	}
}
int DEEP(tree *t)
{
	int DL,DR;
	DL=DR=0;
	if(t==NULL)
	{
		return NULL;
	}
	if(t->left!=NULL)
	{
		DL=DEEP(t->left);
	}
	if(t->right!=NULL)
	{
		DR=DEEP(t->right);
	}
	return (DL>DR?DL:DR)+1;
}
int WID(tree *t)
{
	
	tree *queue[max];
	int front=0,rear=0;
	int MAXLEN;
	tree *s=t;
	if(t!=NULL)
	{
		queue[++rear]=s;
		MAXLEN=rear-front;
		while(front!=rear)
		{
		
			if(rear-front>MAXLEN)
			{
				MAXLEN=rear-front;
			}	
			s=queue[++front];
			if(s->left!=NULL)
			{
				queue[++rear]=s->left;
			}
			if(s->right!=NULL)
			{
				queue[++rear]=s->right;
			}
		}
		return MAXLEN;
	}else 
	{
		return NULL;
	}
}

int main()
{
	int a[]={1,2,0,4,5,0,0,6,0,0,3,0,7,0,8,0,0,};
	int n=0;
	tree *t=buildt(a,n);
	printf("\nthe Pre:\n");
	PreT(t);
	printf("\nthe Mid:\n");
	MidT(t);
	printf("\nthe Lat:\n");
	LatT(t);
	printf("\nthe layer :\n ");
	Layer(t);
	printf("\nthe tree deep is :\n");
	int deep=DEEP(t);
	printf("%d\n",deep);
	printf("\nthe tree Width is :\n");
	int width=WID(t);
	printf("%d",width);
}






