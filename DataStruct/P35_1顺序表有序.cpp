#include <stdio.h>
#include <stdlib.h>
#define maxsize 20
typedef struct d{
	int data[maxsize];
	int length;
}node;
void cass(int *p,int *q);
node *build()
{
	int num;
	node *s=(node *)malloc(sizeof(node));
	int x=1;int y=2;
	for(int i=0;i<9;i++,x+=2)
	{
		s->data[i]=x;
	}
	for(int i=9;i<maxsize-1;i++,y+=3)
	{
		s->data[i]=y;
		s->length=i;
	}
	return s;
}
void bianli(node *s)
{
	node *h=s;
	for(int i=0;i<maxsize-1;i++)
	{
		printf("%d\n",h->data[i]);
	}
	printf("-------------end\n");
}

node *swap(node *head)
{
	node *h;
	for(int i=0;i<9;i++)
	{
		for(int j=9;j<maxsize-1;j++)
		{
			if(h->data[i]>=h->data[j])
			{
				cass(&h->data[i],&h->data[j]);
			}
		}
	}
	return h;
}
void cass(int *p,int *q)
{
	int i=*p;
	*p=*q;
	*q=i;
}


int main()
{
	node *head=build();
	bianli(head);
	node *s=swap(head);
	bianli(s);
}
