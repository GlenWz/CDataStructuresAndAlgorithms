#include <Stdio.h>
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
		return  NULL;
	}
	tree *s=(tree *)malloc(sizeof(tree));
	s->data=num;
	s->left=buildt(a,n);
	s->right=buildt(a,n);
	return s;
}
int Pre(tree *t)
{
	tree *s;
	tree *queue[max];
	int front=0,rear=0;
	if(s!=NULL)
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
	int top=0;
	tree *s=t;
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
	int top1=0,top2=0;
	tree *s=t;
	if(t!=NULL)
	{
		while(top1!=0||s!=NULL)
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
	}else 
	{
		return NULL;
	}
}

int Layer(tree *t)
{
	tree *queue[max];
	int front=0,rear=0;
	if(t!=NULL)
	{
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
//������ʽתΪ˳��洢�Ƿ���Ը�Ϊ����ӽڵ�ֱ�Ӹ�ֵΪ0����������; 
//  ���ԣ����������� ������ֻ��ͨ��˫�׽��Ͷ��ӵĹ�ϵ��,���ѵ���ʱ���ٸ� 

int Convert2node(int a[],tree *t,int deep)
{
	int n=0,DL=0,DR=0,ret=0;
	tree *queue[max],*k=t;
	int front=0,rear=0;
	if(t!=NULL)
	{
		queue[rear++]=t;
		while(front!=rear)
		{
			t=queue[front++];
			if(t->left!=NULL)
			{
				queue[rear++]=t->left;
				++DL;
			}
			if((t->left==NULL)&&DL<deep)
			{
				tree *s=(tree *)malloc(sizeof(tree));
				s->data=0;
				s->left=NULL;
				s->right=NULL;
				t->left=s;
			}
			if(t->right!=NULL)
			{
				queue[rear++]=t->right;
				++DR;
			}
			if((t->right==NULL)&&DR<deep)
			{
				tree *s=(tree *)malloc(sizeof(tree));
				s->data=0;
				s->left=NULL;
				s->right=NULL;
				t->right=s;	
			}
		}
		front=0,rear=0;
		queue[rear++]=k;
		while(front!=rear)
		{
			k=queue[front++];
			a[ret++]=k->data;
			if(k->left!=NULL)
			{
				queue[rear++]=k->left;
			}
			if(k->right!=NULL)
			{
				queue[rear++]=k->right;
			}
		}
	}
	return ret;
}

void PrintA(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
}

int Fleaf(tree *t,int N)
{
	int ret;
	tree *queue[max];
	int front=0,rear=0;
	if(t!=NULL)
	{
		queue[rear++]=t;
		while(front!=rear)
		{
			t=queue[front++];
			if(t->left!=NULL||t->right!=NULL)
			{
				N++;
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
	 } 
	ret=N;
	return ret;
}
int DGLayer(tree *queue[],int &front,int &rear,tree *t,int &N,int &m)
{
	if(t!=NULL||front!=rear)
	{
		++m;
		if(front!=rear)
		{
			t=queue[front++];
			if(t->left!=NULL||t->right!=NULL)
			{
				N++;
			}
			printf("%d->",t->data);
		}
		if(t->left!=NULL&&t->right!=NULL)
		{
			queue[rear++]=t->left;	
			queue[rear++]=t->right;
			DGLayer(queue,front,rear,t->left,N,m);
		}else if(t->left!=NULL&&t->right==NULL)
		{
			queue[rear++]=t->left;
			DGLayer(queue,front,rear,t->left,N,m);
		}else if(t->right!=NULL&&t->left==NULL)
		{
			queue[rear++]=t->right;
			DGLayer(queue,front,rear,t->right,N,m);
		}else
		{
			if(front!=rear)
			{
				DGLayer(queue,front,rear,t,N,m);
			}else
			{
				return NULL;
			}
		}
	}else 
	{
		return NULL;	
	}	
}


int main()
{
	int a[]={1,2,4,0,0,5,0,0,3,0,7,8,0,0,0,};
	int n=0;
	tree *t=buildt(a,n);
	printf("��Ҷ�ӽڵ�ĸ�����\n");
	int N=0,m=0;
	int NUM=Fleaf(t,N); 					//�ǵݹ� 
	printf("%d\n",NUM);
	printf("\n**�ݹ��Ҷ�ӽڵ����:\n");
	tree *Queue[max];
	int front=0,rear=0;
	Queue[rear++]=t;
	DGLayer(Queue,front,rear,t,N,m); 
	printf("\n%d\n%d\n",N,m);
	printf("\n�ǵݹ�ǰ�����:\n");
	Pre(t);
	printf("\n�ǵݹ��������:\n");
	Mid(t);
	printf("\n�ǵݹ�������:\n");
	Lat(t);
	printf("\n���������\n");
	Layer(t);
	printf("\n�������:\n");
	int Deep=DEEP(t);
	printf("%d",Deep);
	printf("\n��ʽ�洢������ת��Ϊ˳��洢:\n");
	int Tree[max];
	int num=Convert2node(Tree,t,Deep);
	PrintA(Tree,num);
	printf("\n˳��洢������ת��Ϊ��ʽ�洢:\n");
	printf("\n�����������������:\n");
	
	
	
}
