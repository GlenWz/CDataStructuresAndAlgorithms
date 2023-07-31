#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef struct d{
	int data[maxsize];
	int length;
}link;

link *build()
{
	link *head;
	head=(link*)malloc(sizeof(link));
	int x=1;
	for(int i=0;i<maxsize-1;i++,x+=3)
	{
		head->data[i]=x;
		head->length=i;
	}
	return head;
}
int DEL(link *head,int &e,int x)
{
	link *h=head;
	for(int i=0;i<maxsize;i++)
	{
		if(h->data[i]==x)
		{
			e=h->data[i];
			for(int j=i;j<h->length;j++)
			{
				h->data[j]=h->data[j+1];
			}
			h->data[h->length]=NULL;
			h->length--;
			return 1;
		}
	}
	return 0;	
}
void SCHU(link *head)
{
	link *h=head;
	for(int i=0;i<h->length;i++)
	{
		printf("%d\n",h->data[i]);
	}
}



int main()
{
	link *head=build();
	link *del;int e;
	SCHU(head);
	int x=7; int f;
	f=DEL(head,e,x);
	printf("fanhui zhi shi %d,e de zhi shi%d\n",f,e);
	SCHU(head);
	
}

