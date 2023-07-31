#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}node;

node *builda()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *h=head;
	for(int i=0;i<10;i++)
	{
		if(i==9)
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
	return h;
}
node *Nizhi(node *head)
{
	node *h,*ret,*q,*p;
	p=ret=head;
	h=head->next;
	for(;h->data!=-1;)
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
	node *aa=Nizhi(a);
	Print(aa);
}
