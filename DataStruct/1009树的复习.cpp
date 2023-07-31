#include <Stdio.h>
#include <stdlib.h>
#include <math.h>
#define  MAXSIZE 100
typedef struct d{
	int data;
	struct d *left, *right;
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
void Pre(tree *t)
{
	tree *stack[MAXSIZE];
	int top=0;
	if(t!=NULL)
	{
		stack[top++]=t;
		while(top!=0&&t!=NULL)
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
		printf("the tree is NULL\n");
		return;
	}
}
void Mid(tree *t)
{
	if(t!=NULL)
	{
		tree *stack[MAXSIZE];
		int top=0;
		while(t!=NULL||top!=0)
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
		tree *stack1[MAXSIZE];
		tree *stack2[MAXSIZE];
		int top1=0,top2=0;
		while(t!=NULL||top1!=0)
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
	if(t!=NULL)		//树不为空 
	{
		tree *queue[MAXSIZE];//创建队列 
		int front=0,rear=0;
		queue[rear++]=t;	//根节点入队 
		while(front!=rear)	//队列为空跳出循环 
		{
			t=queue[front++];//出队列 
			printf("%d->",t->data);
			if(t->left!=NULL)//左孩子不为空进队 
			{
				queue[rear++]=t->left;
			}
			if(t->right!=NULL)//右孩子不为空进队 
			{
				queue[rear++]=t->right;
			}
		}
		
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
		tree *queue[MAXSIZE];
		int front=0,rear=0;
		int MAX=0;
		queue[++rear]=t;
		while(t!=NULL&&front!=rear)
		{
			int n=rear-front;
			if(n>MAX)
			{
				MAX=rear-front;
			}
			for(int i=0;i<n;i++)
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
		return MAX;	
	}else 
	{
		return NULL;
	}
}
void Mirror(tree *t)
{
	tree *tl,*tr,*tmp;
	if(t!=NULL)
	{
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
int Leaft(tree *t)
{
	int ret=0;
	if(t!=NULL)
	{
		tree *queue[MAXSIZE];
		int front=0,rear=0;
		queue[rear++]=t;
		while(front!=rear)
		{
			t=queue[front++];
			if(t->left==NULL&&t->right==NULL)
			{
				++ret;
			}
			if(t->left!=NULL)
			{
				queue[rear++]=t->left;
			}
			if(t->right!=NULL)
			{
				queue[rear++]=t->right;
			}
		}
		return ret;
	}else 
	{
		return ret;
	}
}
int Parentree(tree *t)
{
	int ret=0;
	if(t!=NULL)
	{
		tree *queue[MAXSIZE];
		int front=0,rear=0;
		queue[rear++]=t;
		while(front!=rear)
		{
			t=queue[front++];
			if(t->left!=NULL||t->right!=NULL)
			{
				++ret;
				if(t->left!=NULL)
				{
					queue[rear++]=t->left;
				}
				if(t->right!=NULL)
				{
					queue[rear++]=t->right;
				}
			}
		}
		return ret;
	}else 
	{
		return ret;
	}
}
void Convert2Arry(tree *t,int a[],int index)
{
	
	if(t!=NULL)
	{
		a[index]=t->data;
		Convert2Arry(t->left,a,index*2+1);
		Convert2Arry(t->right,a,index*2+2);	
	}	
}
void PrintCA(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",a[i]);
	}
}
tree *Convert2Link(int a[],int N) //层序遍历创建二叉树 
{
	tree *head=(tree *)malloc(sizeof(tree));
	head->data=a[0];
	tree *ret=head;
	int nl,nr;
	tree *queue[MAXSIZE];
	int front=0,rear=0;
	queue[rear++]=head;
	for(int i=1;i<=N;)
	{
		head=queue[front++];
		nl=a[i++];
		nr=a[i++];
		if(nl!=0)
		{
			tree *l=(tree *)malloc(sizeof(tree));
			l->data=nl;
			l->left=NULL;
			l->right=NULL;
			head->left=l;
			queue[rear++]=l;
		}else 
		{
			head->left=NULL;
		}
		
		if(nr!=0)
		{
			tree *r=(tree *)malloc(sizeof(tree));
			r->data=nr;
			r->left=NULL;
			r->right=NULL;
			head->right=r;
			queue[rear++]=r;
		}else 
		{
			head->right=NULL;
		}
	}
	return ret;
}

int main()
{
	int a[]={1,2,4,0,0,5,0,0,3,6,0,0,0,};
	int n=0;
	tree *t=buildt(a,n);
	printf("非递归前序遍历:\n");
	Pre(t);
	printf("\n非递归中序遍历:\n");
	Mid(t);
	printf("\n非递归后序遍历:\n");
	Lat(t);
	printf("\n层序遍历:\n");
	Layer(t);
	printf("\n树的深度:\n");
	int Deep=DEEP(t);
	printf("DEPP:%d",Deep);
	printf("\nThe tree width:\n");
	int W=Width(t);
	printf("%d",W);
	printf("\nMirror tree:\n");
	Mirror(t);
	Layer(t);
	printf("\nleaft number is :\n");
	int num=Leaft(t);
	printf("%d",num);
	printf("\nParent number is :\n");
	int ParentN=Parentree(t);
	printf("%d",ParentN);
	printf("\n树的链式存储转换为顺序存储:\n");
	int DEP=Deep;
	int MAXTreeNode=pow(2.0,DEP)-1;
//	printf("%d",MAXTreeNode);
	int Arry[MAXTreeNode]={0,};
	int index=0;
	Convert2Arry(t,Arry,index); 
	PrintCA(Arry,MAXTreeNode);
	printf("\n树的顺序存储转换为链式:\n");
	tree *CTree=Convert2Link(Arry,MAXTreeNode);
	Layer(CTree);
}








