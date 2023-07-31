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
	}
	tree *t=(tree *)malloc(sizeof(tree));
	t->data=num;
	t->left=buildt(a,n);
	t->right=buildt(a,n);
	return t;
}
int Pre(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	printf("%d->",t->data);
	Pre(t->left);
	Pre(t->right);
}
int FdgPre(tree *s)
{
	printf("\n非递归前序遍历：\n");  //好像只能用栈 
	tree *stack[max],*t; 
	int top=0;
	if(t!=NULL)
	{
		stack[top++]=s;
		while(top!=0)
		{
			t=stack[--top];      //*****这里要注意啊！！！！！！！！！！！ 
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
	}else 
	{
		return NULL;
	}
}
int Mid(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	Mid(t->left);
	printf("%d->",t->data);
	Mid(t->right);
}

int FdgMid(tree *t)
{
	tree *stack1[];
	tree *stack2[];
	int top1=0,top2=0;
	tree *s;
	if(t!=NULL)
	{
		stack1[top1++]=t;
		stack2[top2++]=t;
		while(top1!=-1)
		{
			s=stack1[--top1];
			if(s->left!=NULL)
			{
				while(s->left!=NULL)
				{
					stack1[top1++]=s->left;
					stack2[top2++]=s->left;
				}
			}
		}
	}
}




int main()
{
	int a[]={1,2,0,4,0,0,3,0,5,0,0,};
	int n=0;
	tree *t=buildt(a,n);
	Pre(t);
	FdgPre(t);
	Mid(t); 
	FdgMid(t);
	
		
}
