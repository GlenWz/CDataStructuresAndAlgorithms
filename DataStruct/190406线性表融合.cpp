#include <Stdio.h>
#include <Stdlib.h>
#define MAXSIZE 20

typedef struct d{
	int data[MAXSIZE];
	int length;
	int pos;
}list;

list *builda()
{
	list *a=(list *)malloc(sizeof(list));
	int j=1;
	a->length=0;
	for(int i=0;i<10;i++)
	{
		a->data[i]=j;
		j++;
		++a->length;
		a->pos=i;
	}
	return a;
}
list *buildb()
{
	list *b=(list *)malloc(sizeof(list));
	int j=1;
	b->length=0;
	for(int i=0;i<10;i++)
	{
		b->data[i]=j;
		j+=2;
		++b->length;
		b->pos=i;
	}
	return b;
}
void print(list *h)
{
	for(int i=0;i<h->length;i++)
	{
		printf("%d->",h->data[i]);
	}
	printf("\n---------------\n");
}
list *merge(list *a,list *b)
{
	int i,j,k,l;
	l=a->length;
	for(i=0,j=0;j<b->length&&i!=a->length-1;)
	{
		if(a->data[i]==b->data[j]||a->data[i+1]==b->data[j])
		{
			j++;
		}else if(a->data[i]<b->data[j]&&a->data[i+1]>b->data[j])
		{
			++a->length;
			for(int t=a->length;t>i;t--)
			{
				a->data[t]=a->data[t-1];
			}
			a->data[i+1]=b->data[j];
			i++;
			j++;
		}else 
		{
			i++;
		}
	}
	if(a->length-1==i&&b->length-1!=j)
	{
		for(int k=a->length;j<b->length;j++,k++)
		{
			a->data[k]=b->data[j];
			++a->length;
		}
	}
	return a;
}

int main()
{
	list *a,*b,*me;
	a=builda();
	b=buildb();
	print(a);
	print(b);
	me=merge(a,b);
	print(me);
}
