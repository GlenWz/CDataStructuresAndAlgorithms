#include <Stdio.h>
#include <Stdlib.h>
#define max 100
typedef struct d{
	int data;
	struct d *left;
	struct d *right;
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
int LatBL(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	LatBL(t->left);
	LatBL(t->right);
	printf("%d->",t->data);
}
int Layer(tree *t)
{
	tree *s;
	tree *queue[max];
	int front=0,rear=0;
	if(t==NULL)
	{
		printf("the tree error!\n");
		return NULL;
	}
	queue[rear++]=t;
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

int DEEP(tree *s)
{
	int DL=0,DR=0;     //这里要初始化为0 啊！！！！！ 
	tree *t=s;
	if(t==NULL)
	{
		return NULL;
	}else
	{
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
}

int Wid(tree *s)
{
	tree *t=s;
	int i,j,front,rear;
	int Max=0;
	front=rear=0;
	tree *queue[max];
	if(t!=NULL)
	{
		rear++;
		queue[rear]=t;
		while(rear!=front)
		{
			int len=rear-front;
			if(Max<len)
			{
				Max=len;
			}
			for(i=0;i<len;i++)
			{
				tree *p=queue[++front];
				if(p->left!=NULL)
				{
					queue[++rear]=p->left;
				}
				if(p->right!=NULL)
				{
					queue[++rear]=p->right;
				}
			}
		}
		return Max;
	}else 
	{
		return 0;
	}
}



int main()
{
	int a[]={1,2,3,0,0,4,5,0,0,6,0,0,7,0,0,};
//		int a[]={1,2,4,0,0,5,0,0,3,6,0,0,7,0,0};

	int len=sizeof(a)/sizeof(a[0]);
	int n=0;
	tree *t=buildt(a,n);
	printf("Pre bian li:\n");
	PreBL(t);
	printf("\nMid bian li:\n");
	MidBL(t);
	printf("\nhou xu bian li :\n");
	LatBL(t);
	printf(" \nlayer bian li :\n");
	Layer(t);
	int Deep=DEEP(t);
	printf("the DEEP is :%d\n",Deep);
	int width=Wid(t);
	printf("The Width is :%d\n",width); 
	
	
}








