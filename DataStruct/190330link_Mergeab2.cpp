#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *builda()
{
	link *head=(link *)malloc(sizeof(link));
	link *h=head;
	head->data=NULL;
	int a[]={1,3,5,7,9,11,13,15,19};
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
link *buildb()
{
	link *head=(link *)malloc(sizeof(link));
	link *h=head;
	head->data=NULL;
	int a[]={2,3,6,9,11,13,15,18,21,23};
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

link *Merge(link *a,link *b)
{
	link *head=a;
	link *pa=a;
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
			pb=b->next;
			b->next=a;
			pa=b;
			b=pb;
			
		}else
		{
			link *f;
			f=b;
			b=b->next;
			pb->next=b;
			pa=a;
			a=a->next;
			free(f);
		}
	}
	if(b!=NULL)
	{
		pa->next=b;
	}
	if(a!=NULL)
	{
		pa->next=a;
	}
	return head;
}

void print(link *head)
{
	link *h=head->next;
	for(h;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("-------------------\n");
}

int main()
{
	link *heada,*headb,*m;
	heada=builda();
	headb=buildb();
	m=Merge(heada,headb);
	print(heada);
	print(headb);
	print(m);
}







