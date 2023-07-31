#include <Stdio.h>
#include <Stdlib.h>
typedef struct d{
	int data;
	struct d *lefft;
	struct d *right;
	int flag=0;
}tree;

tree *build()
{
	int num;
	printf("shuru");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else 
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=num; s->lefft=build();
		s->right=build();
	}
}

int deep(tree *head)
{
	int m=0,n=0;
	if(head==NULL)
	{
		return 0 ;
	}else 
	{
		m=deep(head->lefft);m++;
		n=deep(head->right);n++;
		return (m>n?m:n);
	}
}

int main()
{
	tree *head=build();
	int j=deep(head);
	printf("J=%d",j);
}
