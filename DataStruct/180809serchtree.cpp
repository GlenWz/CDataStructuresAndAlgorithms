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
	printf("shuru");
	scanf("%d",&num);
	if(num==0)
	{
		return 0;
	}else 
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=num;
		s->lefft=build();s->right=build();
	}
}
void search(tree *head,int key,tree *q)
{
	if(head!=NULL)
	{
		if(head->data==key)
		{
			q->lefft=head;
		}else 
		{
			search(head->lefft,key,q);
			search(head->right,key,q);
		}
	}else 
	{
		q
	}
}



void mid(tree *head)
{
	if(head!=NULL)
	{
		mid(head->lefft);
		printf("%d\t",head->data);
		mid(head->right);
	}
}



int main()
{
	tree *head=build();
	mid(head);int key=9;
	tree *q;
	search(head,key,q);
	printf("\nQ=%d\n",q->lefft->data);
}
