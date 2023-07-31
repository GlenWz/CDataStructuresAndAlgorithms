#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef struct{
	int data[maxsize];
	int length;
}sqlist;

sqlist *build()
{
	int i;
	sqlist *q=(sqlist *)malloc(maxsize*sizeof(sqlist));
	for(i=0;i<maxsize;i++)
	{
		q->data[i]=i;
		q->length=i;
	}
	for(i=maxsize-1;i>-1;i--)
	{
		printf("%d\n",q->data[i]);
	}
	return q;
}
sqlist *Del()
{
	sqlist *q,*p;
	int i;
	q=build();
	for(q->length=0;q->length<maxsize;q->length++)
	{
		if(q->length==2)
		{
		//	printf("q->length==2:%d\n",q->data[2]);
			for(i=2;i<maxsize;i++)
			{
				q->data[i]=q->data[i+1];
				q->length=q->length-1;
			}
		}
	}
	return q;
}

int main()
{
	sqlist *q,*del;	
	int i;
	q=build();
	for(q->length=0;q->length<maxsize;q->length++)
	{
		i=q->length;
		printf("M:%d\n",q->data[i]);
		if(q->length==9)
		{
			printf("M9:%d\n",q->data[9]);
		}
	}
	del=Del();
	for(del->length;del->length<maxsize;del->length++)
	{
		i=del->length;
		printf("del:%d\n",del->data[i]);
	}
	
}
