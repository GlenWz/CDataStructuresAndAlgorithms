#include <Stdio.h>
#include <stdlib.h>

#define maxsize 100
typedef struct d{
	int arry[maxsize];
	int length;
}sqlist;

void swap(int *a,int *b)
{
	int c=*a;
	*a=*b;
	*b=c;
}



sqlist* sort(sqlist *q)
{
	sqlist *h=q;
	for(int i=0;i<q->length;i++)
	{
		for(int j=0;j<q->length;j++)
		{
			if(q->arry[j]>q->arry[j+1])
			{
				swap(&q->arry[j],&q->arry[j+1]);
			}
		}
	}
	return h;
}
void print(sqlist *q)
{
	for(int i=0;i<q->length;i++)
	{
		printf("%d->",q->arry[i]);
	}
	printf("\n");
}
sqlist *Insert(sqlist *q,int x)
{
	q->length++;
	sqlist *h=q;
	int pos;
	if(x<q->arry[0])
	{
		for(int  i=q->length;i>0;i--)
		{
			q->arry[i]=q->arry[i-1];
		}
		q->arry[0]=x;
	}else if(x>q->arry[q->length-2])
	{
		q->arry[q->length-1]=x;
	}else 
	{
		for(int i=0;i<q->length;i++)
		{
			if(q->arry[i]>x)
			{
				pos=i;
				for(int j=q->length-1;j>pos;j--)
				{
					q->arry[j]=q->arry[j-1];
				}
				q->arry[pos]=x;
				break;
			}
		}
	}
	
	return h;
}

int main()
{
	sqlist *q=(sqlist *)malloc(sizeof(sqlist)); 
	q->length=15;
	for(int i=0;i<q->length;i++)
	{
		q->arry[i]=rand();
	}
	sqlist *h=sort(q);
	print(h);
	int x=-1;
	int y=99999999;
	int z=888;
	sqlist *later=Insert(h,x);
	print(later);
	sqlist *later2=Insert(h,y);
	print(later2);
	sqlist *later3=Insert(h,z);
	print(later3);
	
}
