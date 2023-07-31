#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *build()
{
	link *head=(link *)malloc(sizeof(link));
	link *h=head;
	head->data=NULL;
	int a[]={1,3,5,7,9,11,13,17,19};
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

link *NIZHI(link *head)
{
	link *h=head->next;
	link *p=head->next;
	link *q=p->next;
	link *qq;
	while(q!=NULL)
	{
		qq=q->next;
		q->next=p;
		p=q;
		q=qq;
	}
	h->next=NULL;
	head->next=p;
	return head;
}
void print(link *head)
{
	link *h;
	for(h=head->next;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n------------------------------------\n");
}




int main()
{
	link *la,*nizhi;
	la=build();
	print(la);
	nizhi=NIZHI(la);
	print(nizhi);
}




