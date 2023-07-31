#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 100

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

tree *buildT(int a[],int &n)
{
	int num=a[n++];
	if(num==0)
	{
		return NULL;
	}else 
	{
		tree *t=(tree *)malloc(sizeof(tree));
		t->data=num;
		t->left=buildT(a,n);
		t->right=buildT(a,n);
		return t;
	}
}
int Mid(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}else
	{
		Mid(t->left);
		printf("%d->",t->data);
		Mid(t->right);
	}
}
void PreMid(tree *t)
{
	tree *stack[maxsize];
	tree *p=t;
	int top=-1;
//	stack[++top]=t;
	while(top!=-1||p!=NULL)
	{
		while(p!=NULL)
		{
			stack[++top]=p;
			p=p->left;
		}
		if(top!=-1)
		{
			p=stack[top--];
			printf("%d->",p->data);
			p=p->right;
		}
	}
}
int Lat(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}else 
	{
		Lat(t->left);
		Lat(t->right);
		printf("%d->",t->data);
	}
}
int NiHoux(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}else
	{
		printf("%d->",t->data);
		NiHoux(t->right);
		NiHoux(t->left);
	}
}
void FdgHouxu(tree *t)
{
	tree *stack[maxsize];
	tree *stack1[maxsize];
	tree *p=t;
	int top=-1;
	int top1=-1;
	while(p!=NULL||top!=-1)
	{
		while(p!=NULL)
		{
			stack[++top]=p;
			stack1[++top1]=p;
			p=p->right;
		}
		if(top!=-1)
		{
			p=stack[top--];
		//	printf("%d->",p->data);
			p=p->left;
		}
	}
	while(top1!=-1)
	{
		printf("%d->",stack1[top1--]->data);
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

int main()
{
	//int a[]={1,2,4,0,0,5,0,0,3,6,0,0,7,0,0};
	int a[]={1,2,4,8,0,0,0,5,0,9,0,0,3,6,0,0,7,10,0,11,0,0,0};
	int len=sizeof(a)/sizeof(a[0]);
	int n=0;
	tree *t=buildT(a,n);
	printf("中序遍历:  "); 
	Mid(t);
	printf("\n后序遍历： "); 
	Lat(t);
	printf("\n非递归中序:");
	PreMid(t);
	printf("\n逆后序遍历:"); //逆后序的实质是先序遍历的左右儿子交换遍历的结果 
	NiHoux(t);
	printf("\n非递归后序:");
	FdgHouxu(t); 
	printf("\n递归前序：");
	DGpre(t); 
}





