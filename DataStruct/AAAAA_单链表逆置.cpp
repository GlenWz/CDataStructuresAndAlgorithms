#include <Stdio.h>
#include <stdlib.h>
#define max 10
typedef struct d{
	int data;
	struct d *next;
}node;
node *builda()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=0;i<10;i++)
	{
		if(i==11)
		{
			node *n=(node *)malloc(sizeof(node));
			n->data=-1;
			n->next=NULL;
			head->next=n;
			head=n;
		}else 
		{
			node *s=(node *)malloc(sizeof(node));
			s->data=i*i;
			s->next=NULL;
			head->next=s;
			head=s;
		}
	}
	return ret;
}
node *NIZHI(node *head)
{
	node *q,*h,*ret,*p;
	ret=p=head;
	h=head->next;
	for(;h!=NULL;)
	{
		q=h->next;
		h->next=p;
		p=h;
		h=q;
	}
	ret->next->next=NULL;
	ret->next=p;
	return ret;
}

void Print(node *head)
{
	node *h=head;
	for(h=h->next;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}
int main()
{
	node *a=builda();	
	Print(a);
	node *aa=NIZHI(a);
	Print(aa);
}
