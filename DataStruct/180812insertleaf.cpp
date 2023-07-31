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
	printf("please input");
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

tree *insert(int x,tree *head)
{
	if(head->lefft==NULL&&head->right==NULL)
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->lefft=s->right=NULL;
		s->data=x;
		if(head->data>x)
		{
			head->lefft=s;
		}else 
		{
			head->right=s;
		}
	}else 
	{
		if(x<head->data)
		{
			head->lefft=insert(x,head->lefft);
		}else if(x>head->data)
		{
			head->right=insert(x,head->right);
		}
	}
	return head;
}

void mid(tree *h)
{
	if(h!=NULL)
	{
		mid(h->lefft);
		printf("%d\t",h->data);
		mid(h->right);
	}
}


int main()
{
	tree *t1=build();
	int x=35;
	tree *ins=insert(x,t1);	
	mid(ins);
	printf("\n------------------------end\n");
}
