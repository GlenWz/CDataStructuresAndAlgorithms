#include <Stdio.h>
#include <Stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *build()
{
	link *head=(link *)malloc(sizeof(link));
	head->data=NULL;
	link *h=head;
	int a[]={2,4,5,6,8,9,111,2233,6542,10};
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=a[i];
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return h;
}

void print(link *head)
{
	link *h;
	for(h=head->next;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n-------------------------------\n");
}
link *NZ(link *head)
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
	h->next=q;
	head->next=p;
	return head;
}

int main()
{
	link *a,*nizhi;
	a=build();
	print(a);
	nizhi=NZ(a);
	print(nizhi);
}












