#include <Stdio.h>
#include <Stdlib.h>

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
	struct d *rtag;
	struct d *ltag;
}tree;

tree *Btnode(int *Mid,int *Pre,int n)
{
	tree *s;
	int *p;
	int k;
	if(n<=0)
	{
		return NULL;
	}
	s=(tree *)malloc(sizeof(tree));
	s->data=*Pre;
	for(p=Mid;p<Mid+n;p++)
	{
		if(*p==*Pre)
		{
			break;
		}
	}
	k=p-Mid;
	s->left=Btnode(Pre+1,Mid,k);
	s->right=Btnode(Pre+k+1,p+1,n-k-1);
	return s;
}
int Print(tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}else 
	{
		printf("%d->",t->data);
		Print(t->left);
		Print(t->right);
	}
}
int main()
{
	int Mid[]={8,4,2,5,9,1,6,3,10,11,7};
	int Pre[]={1,2,4,8,5,9,3,6,7,10,11};
	int n=sizeof(Mid)/sizeof(Mid[0]);
	tree *t=Btnode(Mid,Pre,n);
	Print(t);
}
