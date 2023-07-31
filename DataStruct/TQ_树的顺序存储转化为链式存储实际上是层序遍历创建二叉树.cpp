#include <Stdio.h>
#include <stdlib.h>
#define max 100
typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

tree *buildc(int a[],int len)
{
	int l=0;
	int num,n=0;
	tree *t=(tree *)malloc(sizeof(tree));
	t->data=a[n++];
	tree *ret=t,*s;
	tree *queue[max];
	int front=0,rear=0;
	queue[rear++]=t;
	while(front!=rear&&n<len)
	{
		s=queue[front++];
		num=a[n++];
		printf("\nnumleft:%d\n",num);
		if(num!=0)
		{
			tree *lt=(tree *)malloc(sizeof(tree));
			lt->data=num;
			lt->left=NULL;
			lt->right=NULL;
			s->left=lt;
			queue[rear++]=lt;
		}else 
		{
			s->left=NULL;
		}
		num=a[n++];
		printf("num right %d\n",num);
		if(num!=0)
		{
			tree *rt=(tree *)malloc(sizeof(tree));
			rt->data=num;
			rt->left=NULL;
			rt->right=NULL;
			s->right=rt;
			queue[rear++]=rt;
		}else
		{
			s->right=NULL;
		}
	}
	return ret;
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


int main()
{
	int a[]={1,2,4,0,3,5,0,};
	int len=sizeof(a)/sizeof(a[0]);
	
	tree *t=buildc(a,len);
	Pre(t);
}










