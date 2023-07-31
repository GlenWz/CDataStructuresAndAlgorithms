#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef struct d{
	int data[MAXSIZE];
	int pos;
	int length;
}list;

list *builda()
{
	list *s=(list *)malloc(sizeof(list));
	s->length=10;
	int j=1;
	for(int i=0;i<s->length;i++)
	{
		s->data[i]=j;
		j+=2;
		s->pos=i;
	}
	return s;
}
list *buildb()
{
	list *s=(list *)malloc(sizeof(list));
	s->length=10;
	int j=0;
	for(int i=0;i<s->length;i++)
	{
		s->data[i]=j;
		j++;
		s->pos=i;
	}
	return s;
}
void print(list *h)
{
	for(int i=0;i<h->length;i++)
	{
		printf("%d->",h->data[i]);
		
	}
	printf("\n");
}
list *merge(list *a,list *b)
{
	int i,j,k,l;
	for(i=0,j=0;i!=a->length-1&&j<b->length;)
	{
		if(a->data[i]==b->data[j]||a->data[i+1]==b->data[j])
		{
			j++;
		}else if(a->data[i]<b->data[j]&&a->data[i+1]>b->data[j])
		{
			++a->length;
			for(int s=a->length;s>i;s--)
			{
				a->data[s]=a->data[s-1];
			}
			a->data[i+1]=b->data[j];
			++i;
			++j;
		}else 
		{
			++i;
		}
	}
	if(a->length-1==i&&b->length-1!=j)
	{
		for(int p=a->length;j<b->length;j++,p++)
		{
			a->data[p]=b->data[j];
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
	print(a);
}





