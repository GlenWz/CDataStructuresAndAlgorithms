#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

tree *findmin(tree *t);
tree *build()
{
	int num;
	printf("shuru:");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else 
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=num;
		s->left=build();
		s->right=build();
	}
}
tree *insert(tree *t,int x)
{
	if(t->left==NULL&&t->right==NULL)
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=x;
		s->left=s->right=NULL;
		if(t->data>x)
		{
			t->left=s;
		}else
		{
			t->right=s;
		}
	}else 
	{
		if(t->data>x)
		{
			t->left=insert(t->left,x);
		}else if(t->data<x)
		{
			t->right=insert(t->right,x);
		}else
		{
			printf("error!");
			return 0;
		}
	}
	return t;
}

tree *DEL(tree *t,int x)
{
	if(t==NULL)
	{
		printf("the tree is empty!");
		return 0;
	}else if(t->data>x)
	{
		t->left=DEL(t->left,x);
	} else if(t->data<x)
	{
		t->right=DEL(t->right,x);
	}else
	{
		tree *s;
		if(t->left&&t->right)
		{
			s=findmin(t);
			t->data=s->data;
			t->right=DEL(t->right,s->data);	
		}else 
		{
			s=t;
			if(t->left==NULL)
			{	
				t=t->right;
			}else if(t->right==NULL)
			{	
				t=t->left;
			}
			free(s);
		}
	}
	return t;
}
tree *findmin(tree *t)
{
	tree *min;
	int d=t->data;
	while(t)
	{
		if(t->data<d)
		{
			min=t;
			d=t->data;
			t=t->left;
		}
		t=t->right;
	}
	return min;
}
void mid(tree *t)
{
	if(t)
	{
		mid(t->left);
		printf("%d\t",t->data);
		mid(t->right);
	}
}

int main()
{
	tree *t=build();
	int x=30;
	mid(t);
	printf("\n");
	tree *in=insert(t,x);
	mid(in);
	printf("\n----------------------------------\n");
	tree *del=DEL(in,x);
	mid(del);
	printf("\n-----------------------------------\n");
}
