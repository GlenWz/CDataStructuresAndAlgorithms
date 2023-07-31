#include <Stdio.h>
#include <Stdlib.h>
#define max 100
typedef struct d{
	int data;
	struct d *left,*right;
}tree;

tree *buildt(int a[],int &n)
{
	int num=a[n++];
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

int PreBL(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	printf("%d->",t->data);
	PreBL(t->left);
	PreBL(t->right);
}

int MidBL(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	MidBL(t->left);
	printf("%d->",t->data);
	MidBL(t->right);
}
int Lat(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	Lat(t->left);
	Lat(t->right);
	printf("%d->",t->data);
}

int Layer(tree *t)
{
	tree *s;
	tree *queue[max];
	int front=0,rear=0;
	if(t!=NULL)
	{
		queue[rear++]=t;
	}
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
int DEEP(tree *t)		//求树对深度 
{
	int DL=0,DR=0;
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
int WIDTH(tree *t)		//求树的宽度 
{
	tree *queue[max];
	tree *s;
	int MAX=0;
	int front=0,rear=0;
	if(t!=NULL)
	{
		queue[++rear]=t;
		while(front!=rear)
		{
			int len=rear-front;
			if(len>MAX)
			{
				MAX=len;
			}
			for(int i=0;i<len;i++)
			{
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
		}
		return MAX;
	}else 
	{
		return NULL;
	}
	
}


int main()
{
	int a[]={1,2,4,0,0,5,6,0,0,7,0,0,3,0,0,};
	int n=0;
	tree *t=buildt(a,n);
	printf("the Pre:\n");
	PreBL(t);
	printf("\nthe Mid:\n");
	MidBL(t);
	printf("\nthe Lat:\n");
	Lat(t);
	printf("\nthe Layer:\n");
	Layer(t);
	int Deep=DEEP(t);
	printf("\nthe deep is %d\n ",Deep);
	int Wid=WIDTH(t);
	printf("\nthe Wid:%d\n",Wid);
	
	
}
