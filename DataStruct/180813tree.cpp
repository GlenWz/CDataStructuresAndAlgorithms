#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *lefft;
	struct d *right;
}tree;

tree *build()
{
	int num;
	printf("please input the value");
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

void mid(tree *h)
{
	if(h)
	{
		mid(h->lefft);
		printf("%d\t",h->data);
		mid(h->right);
	}
}

tree *INS(int x,tree *head)
{
	if(head->lefft==NULL&&head->right==NULL)
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=x;
		s->lefft=s->right=NULL;
		if(head->data>x)
		{
			head->lefft=s;
		}else 
		{
			head->right=s;
		}
	}else 
	{
		if(head->data>x)
		{
			head->lefft=INS(x,head->lefft);
		}else
		{
			head->right=INS(x,head->right);
		}
	}
	return head;
}


int main()
{
	int x=35;
	tree *t=build();
	mid(t);
	printf("\n-------------------------------woshinidie\n");
	tree *ins=INS(x,t);
	mid(ins);
	
}
