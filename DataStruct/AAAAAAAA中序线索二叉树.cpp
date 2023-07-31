#include <Stdio.h>
#include <Stdlib.h>

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
	int ltag,rtag;
}tree;

tree *buildTree(int a[],int &n)
{
	int num=a[n++];
	if(num==0)
	{
		return NULL;
	}else 
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=num;
		s->ltag=0;
		s->rtag=0;
		s->left=buildTree(a,n);
		s->right=buildTree(a,n);
		return s;
	}
}
tree *MidThread(tree *t,tree *&pre)
{
	if(t!=NULL)
	{
		MidThread(t->left,pre);
		if(t->left==NULL)
		{
			t->left=pre;
			t->ltag=1;
		}
		if(pre!=NULL&&pre->right==NULL)
		{
			pre->right=t;
			pre->rtag=1;
		}
		pre=t;
		
		MidThread(t->right,pre);
	}
}
tree *FIRST(tree *t)
{
	while(t->ltag==0)
	{
		t=t->left;
	}
	return t;
}
tree *NEXT(tree *t)
{
	if(t->rtag==0)
	{
		return FIRST(t->right);
	}else 
	{
		return t->right;
	}
}

void MidInorder(tree *t)
{
	for(tree *p=FIRST(t);p!=NULL;p=NEXT(p))
	{
		printf("%d->",p->data);
	}
	printf("\n");
}

int main()
{
	int a[]={1,2,4,0,5,0,0,0,3,6,0,8,0,0,7,0,0,};
	int n=0;
	tree *t=buildTree(a,n);
	
	tree *pre=NULL;
	if(t!=NULL)
	{
		MidThread(t,pre);
		pre->right=NULL;
		pre->rtag=1;
	}
	MidInorder(t);	
}







