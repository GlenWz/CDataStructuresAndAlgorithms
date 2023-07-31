#include <stdio.h>
#include <stdlib.h>
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
tree *SwapTree(tree *t)
{
	tree *tl,*tr,*tmp;
	tl=t->left;
	tr=t->right;
	t->left=tr;
	t->right=tl;
	return t;
}
void Mid(tree *t)
{
	if(t==NULL)
	{
		return;
	}
	Mid(t->left);
	printf("%d->",t->data);
	Mid(t->right);
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





int main()
{
	int a[]={1,2,0,3,0,0,4,6,0,0,5,0,0,};
	int n=0;
	tree *t=buildt(a,n);
	Mid(t);
	printf("\nLATER:\n\b");
	tree *tlr=SwapTree(t);
	Mid(tlr);
	printf("\n我们来玩一个镜像的:\n");
	/*如果不考虑空间复杂度，直接遍历创建，问题是考虑空间复杂度怎么搞？？？*/
	
	Mirror(t); 
	Mid(t);
}












