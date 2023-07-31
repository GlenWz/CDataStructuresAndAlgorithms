#include <Stdio.h>
#include <Stdlib.h>
#define MAXSIZE 100
typedef struct d{
	int data;
	int po;
}linkj,linkjl[MAXSIZE];

linkjl *build()
{
	linkjl *s=(linkjl *)malloc(sizeof(linkjl));
	linkjl *h=s;
	for(int i=0,j=1;i<20;i++,j+=2)
	{
		s[i]->data=j;
		s[i]->po=i;
	}
	return h;
}
void print(linkjl *head)
{
	for(int i=0;i<20;i++)
	{
		printf("%d->",head[i]->data);
	}
	printf("\n-------------------------\n");
}

int main()
{
	linkjl *a;
	a=build();
	print(a);
}





