#include <Stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef struct d{
	int data[MAXSIZE];
	int pos;
	int length;
}list;

list *builda()
{
	list *a=(list *)malloc(sizeof(list));
	list *h=a;	
	int j=1;
	int i;
	for(i=0;i<10;i++)
	{
		a->data[i]=j;
		j+=2;
		a->pos=i;
	}
	a->length=i;
	return h;	
}
list *buildb()
{
	list *b=(list *)malloc(sizeof(list));
	int k=1;
	list *h=b;
	int i=0;
	for(;i<10;i++)
	{
		b->data[i]=k;
		k+=3;
		b->pos=i;
	}
	b->length=i;
	return h;
}
void print(list *h)
{
	for(int i=0;i<h->length;i++)
	{
		printf("%d->",h->data[i]);
	}
	printf("\n-------------------------------------\n");
}

list *merge(list *a,list *b)
{
	int len=a->length;
	int i,j,k;
	for(i=0,j=0,k=0;b->data[j]!=b->data[b->length-1]&&i!=a->length-1;)
	{
		if(a->data[i]<b->data[j]&&a->data[i+1]>b->data[j])
		{
			//++k;
			++a->length;
		
			for(int s=a->length;s>i;s--)
			{
				
				a->data[s]=a->data[s-1];
			}
			a->data[i+1]=b->data[j];
			j++;
			i++;
		//	++a->length;
			
		}else if(a->data[i]==b->data[j]||a->data[i+1]==b->data[j])
		{
			j++;
		}else 
		{
			i++;
		}
	}
	if(a->length-1==i&&j!=b->length-1)
	{
		int f=a->length;
		for(;j<b->length;f++)
		{
			a->data[f]=b->data[j];
			j++;
			++a->length;
		}
	}
	printf("\n");
	return a;
}





int main()
{
	list *a,*b,*m;
	a=builda();
	b=buildb();
	print(a);
	print(b);
	m=merge(a,b);
	print(a);
}



