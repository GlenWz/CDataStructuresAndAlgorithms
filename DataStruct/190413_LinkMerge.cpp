#include <Stdio.h>
#include <Stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *builda()
{
	link *head=(link *)malloc(sizeof(link));
	head->data=NULL;
	link *h=head;
	int j=1;
	for(int i=0;i<10;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=j;
		j+=2;
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
	int j=2;
	for(int i=0;i<10;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=j;
		j+=3;
		head->next=s;
		s->next=NULL;
		head=s;
	}
	return h;
}
link *merge(link *a,link *b)
{
	link *h=a;
	link *pa=a;
	a=a->next;
	link *pb=b;
	b=b->next;
	while(a!=NULL&&b!=NULL)
	{
		if(a->data>b->data)
		{
			pb=b->next;
			pa->next=b;
			pa=b;
			b->next=a;
			b=pb;
		}else if(a->data<b->data) 
		{
			pa=a;
			a=a->next;
		}else 
		{
			link *f;
			pa=a;
			a=a->next;
			pb=b->next;
			f=b;
			b=pb;
			free(f);
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
void print(link *head)
{
	link *h;
	for(h=head->next;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}

int main()
{
	link *a,*b,*me;
	a=builda();
	b=buildb();
	print(a);
	print(b);
	me=merge(a,b);
	print(me);
	
}






