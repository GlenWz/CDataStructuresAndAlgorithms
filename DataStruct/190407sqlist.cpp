#include <Stdio.h>
#include <Stdlib.h>

typedef struct d{
	int *data;
	int length;
	int listsize;
}sqlist;

void build(sqlist &a)
{
	a.data=(int *)malloc(sizeof(int)*100);
	a.length=10;
	a.listsize=10;
	for(int i=0;i<a.length;i++)
	{
		a.data[i]=i+3;
	}
	
}
void print(sqlist &a)
{
	for(int i=0;i<a.length;i++)
	{
		printf("%d->",a.data[i]);
	}
}


int main()
{
	sqlist a;
	build(a);
	print(a);
}
