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
	if(num==NULL)
	{
		return NULL;
	}
	tree *s=(tree *)malloc(sizeof(tree));
	s->data=num;
	s->left=buildt(a,n);
	s->right=buildt(a,n);
	return s;
}
void Pre(tree *t)
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
	}else
	{
		printf("树为空");
		return;
	}
}
void Mid(tree *t)
{
	if(t!=NULL)
	{
		tree *stack[max];
		int top=0;
		while(top!=0||t!=NULL)
		{
			while(t!=NULL)
			{
				stack[top++]=t;
				t=t->left;
			}
			if(top!=0)
			{
				t=stack[--top];
				printf("%d->",t->data);
				t=t->right;
			}
		}
	}else
	{
		return; 
	}
}

void Lat(tree *t)
{
	if(t!=NULL)
	{
		tree *stack1[max];
		tree *stack2[max];
		int top1=0,top2=0;
		while(top1!=0||t!=NULL)
		{
			while(t!=NULL)
			{
				stack1[top1++]=t;
				stack2[top2++]=t;
				t=t->right;
			}
			
			if(top1!=0)
			{
				t=stack1[--top1];
				t=t->left;
			}
		}
		while(top2!=0)
		{
			printf("%d->",stack2[--top2]->data);
		}
	}else 
	{
		return;
	}	
}
void Layer(tree *t)
{
	if(t!=NULL)
	{
		tree *queue[max];
		int front=0,rear=0;
		queue[rear++]=t;
		while(front!=rear)
		{
			t=queue[front++];
			printf("%d->",t->data);
			if(t->left!=NULL)
			{
				queue[rear++]=t->left;
			}
			if(t->right!=NULL)
			{
				queue[rear++]=t->right;
			}
		}
	}else 
	{
		return;
	}
}

void Mirror(tree *t)
{
	if(t!=NULL)
	{
		tree *tl,*tr;
		tl=t->left;
		tr=t->right;
		t->left=tr;
		t->right=tl;
		Mirror(t->left);
		Mirror(t->right); 
	}else
	{
		return;
	}
}

int DEEP(tree *t)
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

int Width(tree *t)
{
	if(t!=NULL)
	{
		tree *queue[max];
		int front=0,rear=0;
		int Max=0;
		queue[++rear]=t;
		while(front!=rear)
		{
			int len=rear-front;
			if(Max<len)
			{
				Max=len;
			}
			for(int i=0;i<len;i++)
			{
				t=queue[++front];
				if(t->left!=NULL)
				{
					queue[++rear]=t->left;
				}
				if(t->right!=NULL)
				{
					queue[++rear]=t->right;
				}
			}
		}
		return Max;
	}else 
	{
		return NULL;
	}
}
int Convert2Arry(tree *t,int a[],int index,int &len)
{
	if(t!=NULL)
	{
		len=index+1;
		a[index]=t->data;
		Convert2Arry(t->left,a,index*2+1,len);
		Convert2Arry(t->right,a,index*2+2,len);
		
		
	}else 
	{
		return NULL;
	}
} 
void PrintCA(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d  ",a[i]);
	}
}
tree *Convert2Node(int a[],int len)  //本质上是层序遍历创建二叉树 
{
	if(len!=0)
	{
		int n=0;
		tree *ret;
		tree *queue[max];
		int front=0,rear=0;
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=a[n++];
		queue[rear++]=s;
		ret=s;
		for(;n<len;)
		{
			s=queue[front++];
			if(a[n]!=0)
			{
				tree *lt=(tree *)malloc(sizeof(tree));
				lt->data=a[n];
				lt->left=NULL;
				lt->right=NULL;
				s->left=lt;
				queue[rear++]=lt;
				n++;
			}else 
			{
				s->left=NULL;
				n++;
			}
			if(a[n]!=0)
			{
				tree *rt=(tree *)malloc(sizeof(tree));
				rt->data=a[n];
				rt->left=NULL;
				rt->right=NULL;
				s->right=rt;
				queue[rear++]=rt;
				n++;
			}else
			{
				s->right=NULL;
				n++;
			}
		}
		return ret;
	}else 
	{
		return NULL;
	}
}

int main()
{
	int a[]={1,2,4,0,0,5,0,0,3,7,0,0,0,};
	int n=0;	
	tree *t=buildt(a,n);
	printf("\n非递归前序遍历:\n");
	Pre(t);
	printf("\n非递归中序遍历:\n");
	Mid(t);
	printf("\n非递归后序遍历:\n");
	Lat(t);
	printf("\n层序遍历:\n");
	Layer(t);
	printf("\n对称树:\n");
	Mirror(t);
	Layer(t);
	printf("\n树的深度:\n");
	int deep=DEEP(t);
	printf("%d\n",deep);
	printf("\n树的宽度:\n");
	int width=Width(t);
	printf("%d\n",width);
	printf("\n树的链式存储转换为顺序存储:\n");
	int Array[max]={};
	for(int i=0;i<30;i++)
	{
		Array[i]=0;
	}
	int index=0,len=0;
	Convert2Arry(t,Array,index,len);
	PrintCA(Array,len);
	printf("\n树的顺序存储转换为链式存储:\n");
	
	tree *ct=Convert2Node(Array,len); 
	Layer(ct);
	
}













