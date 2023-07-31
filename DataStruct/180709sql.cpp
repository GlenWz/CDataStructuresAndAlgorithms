#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef struct d{
	int data[maxsize];
	int length;
}sql;

sql *build()
{
	sql *s1=(sql *)malloc((maxsize)*sizeof(sql));
	sql *head;
	head=s1;
	for(int i=0;i<maxsize;i++)
	{
		printf("qing shu ru x de zhi");
		scanf("%d",&s1->data[i]);
	}
	return head;
}

void swap(int *q,int *p)
{
	//printf("in here\n");   jin qu le mei you shi xian shu ju jiao huan 

	int s=*q;
	*q=*p;
	*p=s;
}

sql *maopao()
{
	sql *head;
	head=build();
	int i,j;
	for(i=0;i<maxsize;i++)
	{
		for(j=maxsize;j>i;j--)
		{
			if(head->data[j-1]>head->data[j])
			{
				swap(&head->data[j-1],&head->data[j]);
			}
		//	printf("int \n");
		}
	}
	return head;
}

sql *Del()
{
	sql *head;
	head=maopao();
	for(int i=0;i<sizeof(head->data)/sizeof(head->data[0]);i++)
	{
		if(head->data[i]==5)
		{
			for(int j=i;j<sizeof(head->data)/sizeof(head->data[0]);j++)
			{
				head->data[j]=head->data[j+1];
			}
			head->length--;
			break;
		}
	}
	return head;
}


int main()
{
	sql *p,*q;
	p=build();
	for(int i=0;i<maxsize;i++)
	{
		printf("%d\n",p->data[i]);
	}
	q=maopao();
	for(int i=0;i<sizeof(p->data)/sizeof(p->data[0]);i++)
	{
		printf("data->%d",q->data[i]);
	}
	sql *del;
	del=Del();
	for(int i=0;i<maxsize-2;i++)
	{
		printf("del:%d\n",del->data[i]);
	}
	
	
}
