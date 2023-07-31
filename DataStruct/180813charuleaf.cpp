#include <Stdio.h>
#include <Stdlib.h>

typedef struct d{
	int data;
	struct d *lefft;
	struct d *right;
}tree;

tree *build()
{
	int num;
	printf("input");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else 
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=num;
		s->lefft=build();
		s->right=build();
	}
}

tree *insert(int x,tree *t)
{
	if(t->lefft==NULL&&t->right==NULL)
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=x;
		s->lefft=s->right=NULL;
		if(t->data>x)
		{
			t->lefft=s;
		}else 
		{
			t->right=s;
		}
		return t;
	}else 
	{
		if(x>t->data)
		{
			t->right=insert(x,t->right);
		}else if(x<t->data)
		{
			t->lefft=insert(x,t->lefft);
		}
	}
}
void mid(tree *h)
{
	if(h)
	{
		mid(h->lefft);
		printf("%d\t",h->data);
		mid(h->right);	
	}
}

int main()
{
	tree *t=build();
	int x=25;
	tree *in=insert(x,t);
	mid(in);
}
