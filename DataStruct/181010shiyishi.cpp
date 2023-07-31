#include <Stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef struct d{
	int data[MAXSIZE];
	int left,right;
}array;

array *build()
{
	array *s=(array *)malloc(sizeof(array));
	s->left=0;
	s->right=13;
	for(int i=0;i<s->right;i++)
	{
		s->data[i]=i*i;
	}
	for(int i=s->right;i<MAXSIZE;i++)
	{
		s->data[i]=i+i;
	}
	return s;
}

void sqlist(array *s)
{
	int l,r,tmp;
	for(int i=0,r=s->right;i<MAXSIZE&&s->data[r]!='\0';)
	{
		if(s->data[i]>s->data[r])
		{
			tmp=s->data[i];
			s->data[i]=s->data[r];
			s->data[r]=tmp;
			++r;
		}else 
		{
			++i;
		}
	}
}
void print(array *s)
{
	printf("the :\n");
	for(int i=0;i<MAXSIZE;i++)
	{
		printf("%d->",s->data[i]);
	}
	printf("\n");
}



int main()
{
	array *a=build();
	print(a);
	sqlist(a);
	print(a);
}
