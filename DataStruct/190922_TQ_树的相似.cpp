#include <stdio.h>
#include <stdlib.h>
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
	}
	tree *s=(tree *)malloc(sizeof(tree));
	s->data=num;
	s->left=buildt(a,n);
	s->right=buildt(a,n);
	return s;
}
int  Lat(tree *t)
{
	if(t!=NULL)
	{
		tree *stack1[max];
		tree *stack2[max];
		int top1=0;
		int top2=0;
		tree *s=t;
		while(s!=NULL||top1!=0)
		{
			while(s!=NULL)
			{
				stack1[top1++]=s;
				stack2[top2++]=s;
				s=s->right;
			}
			if(top1!=0)
			{
				s=stack1[--top1];
				s=s->left;
			}
		}
		while(top2!=0)
		{
			printf("%d->",stack2[--top2]->data);
		}
	}	
}
int Juge(tree *ta,tree *tb)
{
	int ret=1;
	if(ta!=NULL&&tb!=NULL)
	{
		tree *queuea[max];
		tree *queueb[max];
		int front1=0,rear1=0;
		int front2=0,rear2=0;
		queuea[rear1++]=ta;
		queueb[rear2++]=tb;
		while(front1!=rear1)
		{
			ta=queuea[front1++];
			tb=queueb[front2++];
			if(ta->left!=NULL)
			{
				if(tb->left!=NULL)
				{
					queuea[rear1++]=ta->left;
					queueb[rear2++]=tb->left;
				}else 
				{
					ret=-1;
					break;
				}
			}else if(ta->left==NULL)
			{
				if(tb->left!=NULL)
				{
					ret=-1;
					break;
				}
			}
			if(ta->right!=NULL)
			{
				if(tb->right!=NULL)
				{
					queueb[rear2++]=tb->right;
					queuea[rear1++]=ta->right;
				}else
				{
					ret=-1;
					break;
				}
			}else if(ta->right==NULL)
			{
				if(tb->right!=NULL)
				{
					ret=-1;
					break;
				}
			}
		}
	}else 
	{
		if(ta==NULL)
		{
			if(tb!=NULL)
			{
				ret=-1;
			}
		}
		if(ta!=NULL)
		{
			if(tb==NULL)
			{
				ret=-1;
			}
		}
	}
	return ret;
}

tree* Chai(tree *t,int n)
{
	tree *ret,*headb;
	tree *stack[max];
	int top=0;
	if(t->data==n)
	{
		ret=t->right;
		t->right=NULL;
		return ret;
	}
	if(t!=NULL)
	{
		stack[top++]=t;
		while(top!=0)
		{
			t=stack[--top];
			if(t->right!=NULL)
			{
				if(t->right->data==n)
				{
					ret=t->right;
					t->right=NULL;
					return ret;
				}
				stack[top++]=t->right;
			}
			if(t->left!=NULL)
			{
				if(t->left->data==n)
				{
					ret=t->left;
					t->left=NULL;
					return ret;
				}
				stack[top++]=t->left;
			}
		}
	}
}
int FDG_PRE(tree *t)
{
	tree *stack[max];
	int top=0;
	if(t!=NULL)
	{
		stack[top++]=t;
		while(top!=0)
		{
			t=stack[--top];
			printf("%d->",t->data);
			if(t->right!=NULL)
			{
				stack[top++]=t->right;
			}
			if(t->left!=NULL)
			{
				stack[top++]=t->left;
			}
		}
	}
}



int main()
{
	int a[]={1,2,0,4,0,0,3,5,0,0,0};
	int b[]={2,4,0,8,0,0,6,7,0,0,0,};
	int m=0;
	int n=0;
	tree *ta=buildt(a,n);
	tree *tb=buildt(b,m);
	printf("\n树的后序非递归遍历:\n"); 
	Lat(ta);
	printf("\n");
	Lat(tb);
	int ko=Juge(ta,tb);
	printf("\n树是否为相似的，相似的返回1，不是返回-1");	
	printf("\n%d\n",ko);
	
	tree *sb=Chai(tb,6); 
	printf("\n");
	FDG_PRE(sb);
	printf("\n");
	FDG_PRE(tb);
}



