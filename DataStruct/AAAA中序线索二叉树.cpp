#include <Stdio.h>
#include <Stdlib.h>

typedef struct d{
	int  data;
	struct d *left;
	struct d *right;
	int rtag,ltag;
}tree;

tree *buildt(int a[],int &n)
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
		s->left=buildt(a,n);
		s->right=buildt(a,n);
		return s;
	}m
}
tree *Midthread(tree *t,tree *&pre)
{
	if(t!=NULL)
	{
		Midthread(t->left,pre); //线索化左子树 
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
		Midthread(t->right,pre);  // 线索化右子树 
	}
}
tree *First(tree *t)
{
	while(t->ltag==0)
	{
		t=t->left;
	}
	return t;
}
tree *Next(tree *t)
{
	if(t->rtag==0)
	{
		return First(t->right);
	}else
	{
		return t->right;
	}
}



void Midinorder(tree *t)
{
	for(tree *p=First(t);p!=NULL;p=Next(p))
	{
		printf("%d->",p->data);
	}
	printf("\n");
}


int main()
{
	int a[]={1,2,4,0,0,5,0,0,3,0,0,};
	int n=0;
	tree *t=buildt(a,n);
	tree *pre=NULL;
	if(t!=NULL)
	{
		Midthread(t,pre);
		pre->right=NULL;
		pre->rtag=1;
	}
	Midinorder(t); 
}


















