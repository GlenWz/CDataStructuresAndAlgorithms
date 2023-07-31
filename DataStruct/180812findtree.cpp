#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *lefft;
	struct d *right;
}tree;

tree* build()
{
	int num;
	printf("please input the val");
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
		return s;
	}
	
}

int find(tree *s,int x)
{
	while(s!=NULL)
	{
		if(x>s->data)
		{
			s=s->right;
		}else if(x<s->data)
		{
			s=s->lefft;
		}else if(x==s->data)
		{
			return s->data;
		}
	}
	printf("404 not find\n");
	return -1;
}

int main()
{
	tree *s=build();
	int x=22;int ret=1;
	int b;
	b=find(s,x);
	printf("%d\n",b);
	return 0;
}
