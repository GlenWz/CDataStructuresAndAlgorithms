#include <stdio.h>
#include <stdlib.h>
#define maxsize 20

typedef struct d{
	int data[maxsize];
	int topL;
	int topR;
}que;

que *build()
{
	que *head=(que*)malloc(sizeof(que));
	int l=5;int r=20;
	for(int i=0;i<5;i++,l++)
	{
		head->data[i]=l;
		head->topL=i;
	}
	for(int i=maxsize-1;i>head->topL;i--,r++)
	{
		head->data[i]=r;
		head->topR=i;
	}
	return head;
}
void schu(que *head)
{
	que *p;
	p=head;
	for(int i=p->topL;i>-1;i--)
	{
		printf("L=%d\n",p->data[i]);
	}
	for(int i=p->topR;i<maxsize;i++)
	{
		printf("R=%d\n",p->data[i]);
	}
	printf("------------------------------end\n");
}
int DEL(que *head,int tag)
{
	int ret;
	que *h;h=head;
	if(tag==1)
	{
		if(head->topL==-1)
		{
			printf("ni nai nai de the queue is empty!");
		}
		else
		{
			ret=h->data[h->topL];
			h->data[h->topL]=NULL;
			h->topL--;
		}
	}
	else
	{
		if(head->topR==maxsize)
		{
			printf("ni mama de the queue is empty!");
		}
		else
		{
			ret=h->data[h->topR];
			h->data[h->topR]=NULL;
			h->topR--;
		}
	}
	return ret;
}

int main()
{
	que *head,*in;
	head=build();
	schu(head);
	int d; int tag1=1; int tag2=2;
	d=DEL(head,tag1);
	printf("the delete is %d\n",d);
	schu(head);
	in=INPUT();
	
	
}
