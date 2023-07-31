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
	printf("please input the V");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else 
	{
		tree *s =(tree *)malloc(sizeof(tree));
		s->data=num;
		s->lefft=build();
		s->right=build();
	}
}

int deep(tree *head)
{
	int l=0,r=0;
	if(head==NULL)
	{
		return 0;
	}else 
	{
		l=deep(head->lefft);l++;
		r=deep(head->right);r++;
		return (l>r?l:r);
	}
}


int main()
{
	tree *t1=build();
	int deep1;
	deep1=deep(t1);
	printf("the deep is %d",deep1);
}
