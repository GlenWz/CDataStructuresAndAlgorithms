#include <stdio.h>
#include <stdlib.h>
#define len 15
typedef struct d{
	int a[len]={0};
	int length;
}sqlist;

sqlist *build()
{
	sqlist *h=(sqlist *)malloc(sizeof(sqlist));
	h->a[0]=10;
	h->length=1;
	for(int i=1;i<10;i++)
	{
		h->a[i]=i+i;
		h->length++;
	}
	return h;
}
sqlist *BianHuan(sqlist *h)
{
	int i,j,c;
	for(i=1,c=1,j=len-1;c<h->length;c++)
	{
		if(h->a[c]<=h->a[0])
		{
			h->a[i]=h->a[c];
			i++;
		}else 
		{
			--j;
			printf("*%d *%d\n",j,c);
			
			h->a[j]=h->a[c];
		}
	}
	
	if(j>i)
	{
		for(;j>i;j--)
		{
			h->a[j-1]='\0';
		}
	}
	return h;
}
void Print(sqlist *h)
{
	for(int i=0;i<len-1;i++)
	{
		printf("%d ",h->a[i]);
	}
	
}


int main()
{
	sqlist *a=build();
	Print(a);
	printf("\n");
	sqlist *BH=BianHuan(a);
	Print(BH);
}
