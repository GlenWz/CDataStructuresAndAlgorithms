#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *lefft;
	struct d *right;
}tree;

tree *maxT(tree *t);
tree *minT(tree *t);


tree *build()
{
	int num;
	printf("     :");
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
tree *DEL(tree *t,int x)
{
	tree *postmp;
	if(!t)
	{
		printf("the xxx is empty!");
		return 0;
	}else if(x<t->data) 
	{
		t->lefft=DEL(t->lefft,x);
	}else if(x>t->data)
	{
		t->right=DEL(t->right,x);
	}else 
	{
		if(t->lefft&&t->right)
		{
			postmp=minT(t->right);
			t->data=postmp->data;
			t->right=DEL(t->right,t->data);
		}else 
		{
			postmp=t;
			if(!t->lefft)
			{
				t=t->right;
			}else if(!t->right)
			{
				t=t->lefft;
			}
			free(postmp);
		}
	}
	return t;
}
tree *maxT(tree *t)
{
	tree *max;
	int d=t->data;
	while(t)
	{
		if(t->data>d)
		{
			t=t->right;
			max=t;
			d=t->data;
		}
		t=t->lefft;
	}
	return max;
}

tree *minT(tree *t)
{
	tree *min;
	int d=t->data;
	while(t)
	{
		if(t->data<d)
		{
			min=t;
			t=t->lefft;
			d=t->data;
		}
		t=t->right;
	}
	return min;
}
void output(tree *h)
{
	if(h)
	{
		output(h->lefft);
		printf("%d\t",h->data);
		output(h->right);
	}
}

int main()
{
	tree *t=build();
	int x=30;
	tree *del=DEL(t,x);
	output(del);
	printf("\n----------------------end\n");
}
