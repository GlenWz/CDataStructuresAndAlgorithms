#include <stdio.h>
#include <stdlib.h>
#define len 15

typedef struct d{
	int data;
	struct d *next;
}node;

node *builda()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=0;i<len;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		if(i%2==0)
		{
			s->data=i+i-i;
		}else 
		{
			s->data=i+i;
		}
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *Sort_A(node *head)
{
	node *pa,*qa,*h,*ret;
	ret=head;
	for(int i=0;i<len;i++)
	{
		for(h=head,pa=h->next,qa=pa->next;qa!=NULL;)
		{
			if(qa->data>pa->data)
			{
				pa->next=qa->next;
				qa->next=pa;
				h->next=qa;
				h=h->next;
				qa=pa->next;
			}else 
			{
				h=h->next;
				pa=pa->next;
				qa=qa->next;
			}
		}
	}
	return ret;
}
node *DelCF(node *head)
{
	node *h=head;
	node *ret=head;
	node *ph,*qh;
	for(ph=h,qh=ph->next;qh!=NULL;)
	{
		if(ph->data==qh->data)
		{
			node *f=qh;
			ph->next=qh->next;
			qh=ph->next;
			free(f);
		}else 
		{
			ph=qh;
			qh=qh->next;
		}
	}
	return ret;
}
void Print(node *head)
{
	node *h=head;
	for(h=h->next;h!=NULL;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}

int main()
{
	node *a=builda();
	node *Sa=Sort_A(a);
	Print(Sa);
	node *Del=DelCF(Sa);
	Print(Del);
}






