#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *builda()
{
	int a[]={1,3,5,7,9,10,11,12,13,17,19};
	link *head=(link *)malloc(sizeof(link));
	head->data=NULL;
	head->next=NULL;
	link *h=head;
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		link *s=(link *)malloc(sizeof(link));
		head->next=s;
		s->data=a[i];
		s->next=NULL;
		head=s;
	}
	return h;
}
link *buildb()
{
	int b[]={2,4,6,8,10,14,18,20};
	link *head=(link *)malloc(sizeof(link));
	head->next=NULL;
	head->data=NULL;
	link *h=head;
	for(int i=0;i<sizeof(b)/sizeof(b[0]);i++)
	{
		link *s=(link *)malloc(sizeof(link));
		head->next=s;
		s->data=b[i];
		s->next=NULL;
		head=s;
	}
	return h;
}
void print(link *head)
{
	link *h=head->next;
	for(h;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n--------------------------------\n");
}
link *merge(link *a,link *b)
{
	link *pa=a;
	link *h=a;
	a=a->next;
	link *pb=b;
	b=b->next;
	while(a!=NULL&&b!=NULL)
	{
		if(a->data<b->data)
		{
			pa=a;
			a=a->next;
		}else if(a->data>b->data)
		{
			pa->next=b;
			pb->next=b->next;
			b->next=a;
			pa=pa->next;
			b=pb->next;
		}else 
		{
			pb=b;
			b=b->next;
		}
	}
	if(a!=NULL)
	{
		pa->next=a;
	}
	if(b!=NULL)
	{
		pa->next=b;
	}
	return h;
}


int main()
{
	link *la,*lb,*me;
	la=builda();
	lb=buildb();
	print(la);
	print(lb);
	me=merge(la,lb);
	print(me);
}







