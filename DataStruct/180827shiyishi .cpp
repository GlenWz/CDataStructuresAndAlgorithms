#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 10

typedef struct d{
	int *ele;
	int size;
}tree;

tree *build()
{
	tree *s=(tree *)malloc(sizeof(tree));
	s->ele=(int *)malloc(sizeof(int)*(maxsize+1));
	s->ele[0]=NULL;
	int j=0;
	s->size=0;
	for(int i=1;i<maxsize+1;i++,j++)
	{
		s->ele[i]=j;
		s->size++;
	}
	return s;
}
void order(tree *s)
{
	int i;
	int tmp;
	int parent=1,childl,childr;
		childl=parent*2;
		childr=childl+1;
		if((childr<=s->size)&&s->ele[parent]<s->ele[childl])
		{
			printf("i am here\n");
			tmp=s->ele[parent];
			s->ele[parent]=s->ele[childl];
			s->ele[childl]=s->ele[parent];
			parent++;
			order(s);
		}else if((childr<=s->size)&&s->ele[parent]>s->ele[childr])
		{
			printf("i am here1\n");
			tmp=s->ele[parent];
			s->ele[parent]=s->ele[childr];
			s->ele[childr]=s->ele[parent];
			parent++;
			order(s);
		}else if((childr<=s->size)&&s->ele[childl]>s->ele[childr])
		{
			printf("i am here2\n");
			tmp=s->ele[childr];
			s->ele[childr]=s->ele[childl];
			s->ele[childl]=tmp;
			parent++;
			order(s);
		}
}
void print(tree *s)
{
	for(int i=0;i<=s->size;i++)
	{
		printf("%d\t",s->ele[i]);
	}
	printf("\n------------------------------------------------------\n");
}



int main()
{
	tree *t=build();
	order(t);
	print(t);	
}
