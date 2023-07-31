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
	printf("please input:");
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
void pre(tree *t)
{
	if(t!=NULL)
	{
		pre(t->lefft);
		printf("%d",t->data);
		pre(t->right);
	}
}




int main()
{
	tree *t=build();
	pre(t);
}
