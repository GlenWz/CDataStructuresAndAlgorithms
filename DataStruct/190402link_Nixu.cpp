#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *builda()
{
	link *head=(link *)malloc(sizeof(link));
	head->data=NULL;
	link *h=head;
	int a[]={1,3,5,7,9,11,13,15,17};
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=a[i];
		head->next=s;
		s->next=NULL;
		head=s;
	}
	return h;
}
link *Nixu(link *head)
{
	link *p=head->next;
	link *q=p->next;
	link *qq;
	link *h=head;
	for(int i=0;i<8;i++)
	{
		qq=q->next;
		q->next=p;
		p=q;
		q=qq;
	}
	head->next->next=qq;
	h->next=p;
	return h;
}
void print(link *head)
{
	link *h=head;
	for(h=h->next;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n----------------------");
}

int main()
{
	link *la,*nixu;
	la=builda();
	print(la);
	nixu=Nixu(la);
	print(nixu);
}





