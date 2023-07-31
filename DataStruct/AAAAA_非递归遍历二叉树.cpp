#include <Stdio.h>
#include <Stdlib.h>
#define MAX 100

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
int DGmid(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}else 
	{
		DGmid(t->left);
		printf("%d->",t->data);
		DGmid(t->right);
	}
}
void Layer(tree *t)
{
	tree *queue[MAX];
	int front=0,rear=0;
	tree *s=t;
	if(s!=NULL)
	{
		queue[rear++]=s;
	}
	while(rear!=front)
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
	printf("\n");
}

void FDGMID(tree *t)
{
	tree *stack[MAX];
	int top=-1;
	tree *s=t;
	while(s!=NULL||top!=-1)
	{
		while(s!=NULL)
		{
			stack[++top]=s;
			s=s->left;
		}
		if(top!=-1)
		{
			s=stack[top--];
			printf("%d->",s->data);
			s=s->right;
		}
	}
	printf("\n");
}

void FDGPRE(tree *t)
{
	tree *stack[MAX];
	int top=-1;
	tree *s=t;
	stack[++top]=s;
	while(top!=-1)
	{
		s=stack[top--];
		printf("%d->",s->data);
		if(s->right!=NULL)
		{
			stack[++top]=s->right;
		}
		if(s->left!=NULL)
		{
			stack[++top]=s->left;
		}
	}
	
}
int DGpre(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}else 
	{
		printf("%d->",t->data);
		DGpre(t->left);
		DGpre(t->right);
	}
}
int DGlat(tree *s)
{
	if(s==NULL)
	{
		return NULL;
	}else
	 {
	 	DGlat(s->left);
	 	DGlat(s->right);
	 	printf("%d->",s->data);
	 }
}
void FDGlat(tree *t)
{
	tree *stack[MAX];
	tree *stack1[MAX];
	int top=-1;
	int top1=-1;
	tree *s=t;
	while(s!=NULL||top!=-1)
	{
		while(s!=NULL)
		{
			stack[++top]=s;
			stack1[++top1]=s;
			s=s->right;
		}
		if(top!=-1)
		{
			s=stack[top--];
			s=s->left;
		}
	}
	while(top1!=-1)
	{
		printf("%d->",stack1[top1--]->data);
	}
}


int main()
{
	int a[]={1,2,4,8,0,0,0,5,0,9,0,0,3,6,0,0,7,10,0,11,0,0,0};
	int n=0;
	tree *t=buildt(a,n);
	DGmid(t);
	printf("\n");
	FDGMID(t);
	Layer(t);
	DGpre(t);
	printf("\n");
	FDGPRE(t);
	printf("\n");
	DGlat(t);
	printf("\n");
	FDGlat(t);
	
}









