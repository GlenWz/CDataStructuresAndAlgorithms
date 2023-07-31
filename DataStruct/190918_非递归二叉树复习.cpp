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
	}
	tree *s=(tree *)malloc(sizeof(tree));
	s->data=num;
	s->left=buildt(a,n);
	s->right=buildt(a,n);
	return s;
}
int Pre(tree *t)
{
	tree *queue[max];
	tree *s;
	int front=0,rear=0;
	if(t!=NULL)
	{
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
	}else 
	{
		return NULL;
	}
}
int Mid(tree *t)
{
	tree *stack[max];
	tree *s=t;
	int top=0;
	if(t!=NULL)
	{
		while(top!=0||s!=NULL)
		{
			while(s!=NULL)
			{
				stack[top++]=s;
				s=s->left;
			}
			if(top!=0)
			{
				s=stack[--top];
				printf("%d->",s->data);
				s=s->right;
			}
		}
	}else 
	{
		return NULL;
	}
}

int Lat(tree *t)
{
	tree *stack1[max];
	tree *stack2[max];
	tree *s=t;
	int top1=0;
	int top2=0;
	if(t!=NULL)
	{
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




int main()
{
	int a[]={1,2,0,5,0,0,3,6,0,0,0,};
	int n=0;
	tree *t=buildt(a,n);
	printf("\n非递归前序遍历:\n");
	Pre(t);
	printf("\n非递归中序遍历:\n");
	Mid(t);
	printf("\n非递归后序遍历:\n");
	Lat(t);
	
}










