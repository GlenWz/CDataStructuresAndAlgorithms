#include <stdio.h>
#include <stdlib.h>
#define max 100
typedef struct d{
	int data;
	struct d* left;
	struct d *right;
}tree;

tree *buildt(int a[],int &n)
{
	int num=a[n++];
	if(num==0)
	{
		return NULL;
	}
	tree  *s=(tree *)malloc(sizeof(tree));
	s->data=num;
	s->left=buildt(a,n);
	s->right=buildt(a,n);
	return s;
}

int Pre(tree *t)
{
	if(t!=NULL)
	{
		tree *stack[max];
		int top=0;
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
		return NULL;
	}
}
int Mid(tree *t)
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
		return NULL;
	}
}

int Lat(tree *t)
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
		return NULL;
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




void Convert2Arry(int arry[],tree *t,int index)
{
	if(!t)
	{
		return;
	}
	arry[index]=t->data;
	Convert2Arry(arry,t->left,index*2+1);
	Convert2Arry(arry,t->right,index*2+2);
}

void PrintA(int arry[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d  ",arry[i]);
	}
	printf("\n");
}
int FdgConvert(int a[],tree *t,int index)  //写不出来啊！！！！！！！！！！ 
{
	
}

int Judge(tree *t)
{
	int ret=1;
	if(t!=NULL)
	{
		tree *tr=t;
		tree *queue[max];
		tree *queur[max];
		int front=0,rear=0;
		int front1=0,rear1=0;
		if(t->left!=NULL)
		{
			if(t->right==NULL)
			{
				ret=-1;
				return ret;
			}else 
			{
				queue[rear++]=t->left;
				tr=t->right;
			}
			while(front!=rear)
			{
				t=queue[front++];
				tr=queur[front1++];
				if(t->left!=NULL)
				{
					if(tr->right==NULL)
					{
						ret=-1;
						break;
					}else 
					{
						queue[rear++]=t->left;
						queur[rear1++]=tr->right;
					}
				}
				if(t->right!=NULL)
				{
					if(tr->left==NULL)
					{
						ret=-1;
						break;
					}else 
					{
						queue[rear++]=t->right;
						queur[rear1++]=tr->left;
					}
				}
			}
			return ret;
		}
		
	}else 
	{
		return NULL;
	}
}





int main()
{
	int a[]={1,2,0,4,0,0,5,6,0,0,0,};
	int n=0;
	tree *t=buildt(a,n);
	printf("非递归前序遍历:\n");
	Pre(t);
	printf("\n非递归中序遍历:\n");
	Mid(t);
	printf("\n非递归后序遍历:\n");
	Lat(t);
	printf("\n树的深度:\n");
	int deep=DEEP(t);
	printf("\n%d\n",deep); 
	printf("\n递归链式转为顺序存储:\n");
	
	int arr[deep*deep];
	for(int i=0;i<deep*deep;i++)
	{
		arr[i]=0;
	}
	int index=0;
	Convert2Arry(arr,t,index);
	PrintA(arr,deep*deep);
	printf("\n非递归链式转顺序存储:\n");
	int a[deep*deep];
	for(int i=0;i<deep*deep;i++)
	{
		a[i]=0;
	}
	int len;
	len=FdgConvert(a,t,index);
	printf("\n判断是否为对称树，是返回1，不是返回-1\n");
	int TF=Judge(t);
	printf("%d",TF); 
	
	printf("\n")
	
}























