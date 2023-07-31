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
	tree *s=(tree *)malloc(sizeof(tree));
	s->data=num;
	s->left=buildt(a,n);
	s->right=buildt(a,n);
	return s;
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
int convert(int a[],tree *t)  //直接一个层序遍历不就把链式的转进顺序存储里面了吗？？ 
{							  //这个是完全二叉树，链式转顺序存储！ 
	tree *queue[100];
	int top=0;
	tree *s=t;
	int front=0,rear=0;
	if(t==NULL)
	{
		printf("the tree is NULL!\n");
	 } 
	queue[rear++]=s;
	
	while(front!=rear)
	{
		s=queue[front++];
		a[top++]=s->data;
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
	return top;
}
void Print(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
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
tree *ConvertTree(tree *t,int deep)
{
	tree *ret=t;
	int DL=0,DR=0;
	tree *queue[max];
	tree *s;
	int front=0,rear=0;
	if(t==NULL)
	{
		printf("the tree is NULL !\n");
		return NULL;
	}
	queue[rear++]=t;
	while(front!=rear)
	{
		s=queue[front++];
		if(s->left!=NULL)
		{
			DL++;
			queue[rear++]=s->left;
		}else if(s->left==NULL&&DL<deep)
		{
			DL++;
			tree *tmp=(tree *)malloc(sizeof(tree));
			tmp->data=0;
			tmp->left=NULL;
			tmp->right=NULL;
			s->left=tmp;
		}
		if(s->right!=NULL)
		{
			DR++;
			queue[rear++]=s->right;
		}else if(s->right==NULL&&DR<deep)
		{
			DR++;
			tree *tmp=(tree *)malloc(sizeof(tree));
			tmp->data=0;
			tmp->left=NULL;
			tmp->right=NULL;
			s->right=tmp;
		}
	}
	return ret;
}



int main()
{
	int a[]={1,2,4,0,0,5,0,0,3,6,0,0,7,0,0,};
	int n=0;
	tree *t=buildt(a,n);
	Pre(t);	
	printf("\n");
	n++;
	int seqa[n];
	int len=convert(seqa,t);
	printf("\n");
	Print(seqa,len);
	
	int b[]={1,2,0,3,0,0,0,};
	int m=0;
	tree *t1=buildt(b,m);
	Pre(t1);
	int Dp1=DEEP(t1);
	printf("\nthe DEEP IS %d\n",Dp1);
	tree *ct=ConvertTree(t1,Dp1);
	Pre(ct);
	printf("\n");
	int cta[n];
	int lenct=convert(cta,ct);
	printf("\n");
	Print(cta,lenct);
	
	printf("\n把树改一下:\n");
	int c[]={1,2,0,3,0,0,4,5,0,0,0,};
	int nc=0;
	tree *tc=buildt(c,nc);
	int dpc=DEEP(tc);
	Pre(tc);
	printf("\n");
	tree *tcc=ConvertTree(tc,dpc);
	printf("\n");
	int atcc[max];
	int lentcc=convert(atcc,tcc);
	printf("\n");
	Print(atcc,lentcc); 
	
}







