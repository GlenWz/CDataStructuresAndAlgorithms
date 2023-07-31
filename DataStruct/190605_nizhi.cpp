#include <Stdio.h>
#include <Stdlib.h>
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
		node *s=(node *)malloc(sizeof(node));
		s->data=i+i;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *nizhi(node *head)
{
	node *ret,*q,*h,*p;
	ret=p=head;
	h=head->next;
	for(;h->next!=NULL;)
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
	node *h;
	for(h=head->next;h!=NULL;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}

int main()
{
	node *a=builda();
	Print(a);
	nizhi(a);
	Print(a);
}
