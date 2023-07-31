#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int *data;
	int length;
	int size;	
}array;

array *builda()
{
	
	array la;
	array *h=la;
	la.data=(int *)malloc(sizeof(int *)*10);
	la.size=10;
	for(int i=0;i<10;i++)
	{
		la.data[i]=i;
		la.length=i;
	}
	return h;
}
void print(array *h)
{
	for(int i=0;i<10;i++)
	{
		printf("%d->",h.data[i]);
	}
	printf("\n---------------------------\n");
}




int main()
{
	array *a,*b,*me;
	a=builda();
	print(a);
}
