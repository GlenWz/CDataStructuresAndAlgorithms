#include <stdio.h>
#include <stdlib.h>
#define len 25
typedef struct d{
	int a[len];
	int lenght;
}sqlist;

sqlist *build()
{
	sqlist *sqla=(sqlist *)malloc(sizeof(sqlist));
	for(int i=0;i<len;i++)
	{
		sqla->a[i]=i+i;
		sqla->lenght=i+1;
	}
	return sqla;
}
sqlist *nizhi(sqlist *sqla)
{
	int i,j,tmp;
	for(i=0,j=sqla->lenght-1;i<j;j--,i++)
	{
		tmp=sqla->a[i];
		sqla->a[i]=sqla->a[j];
		sqla->a[j]=tmp;
	}
	return sqla;
}
sqlist *DelSql(int x,int y,sqlist *h)
{
	int i,j,cha,t;
	cha=(y-x)+1;
	for(i=x-1,j=y;j<h->lenght;i++,j++)
	{
		h->a[i]=h->a[j];
		
	}
	for(t=i;t<h->lenght;t++)
	{
		h->a[t]='\0';
	}
	h->lenght=h->lenght-cha;
	return h;
}

void PrintSql(sqlist *h)
{
	for(int i=0;i<h->lenght;i++)
	{
		printf("%d->",h->a[i]);
	}
	printf("\n");
}


int main()
{
	sqlist *a=build();
	PrintSql(a);
	sqlist *n=nizhi(a);
	PrintSql(n);
	int i=5,j=10;
	sqlist *del=DelSql(i,j,n);
	PrintSql(del);
}
