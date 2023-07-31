#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *builda()
{
	link *head=(link *)malloc(sizeof(link));
	head->next=NULL;
	int a[]={1,3,5,7,9,20,25,-1};
	link *h=head;
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		if(a[i]==-1)
		{
			return h;
		}else 
		{
			link *s=(link *)malloc(sizeof(link));
			s->data=a[i];
			s->next=NULL;
			head->next=s;
			head=s;
		}
	}
}
link *buildb()
{
	link *head=(link *)malloc(sizeof(link));
	link *h=head;
	head->next=NULL;
	int b[]={2,4,6,7,8,9,10,-1};
	for(int i=0;i<sizeof(b)/sizeof(b[0]);i++)
	{
		if(b[i]==-1)
		{
			return h;
		}else 
		{
			link *s=(link *)malloc(sizeof(link));
			s->data=b[i];
			s->next=NULL;
			head->next=s;
			head=s;
		}
	}
}

link *merge(link *a,link *b)
{
	link *head=a;
	link *pa=a;
	a=a->next;
	link *re=b;
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
			re=b->next;
			b->next=a;
			pa=b;
			b=re;
		}else
		{
			link *s=b;
			b=b->next;
			re->next=b;
			pa=a;
			a=a->next;
			free(s);
		}
		
	}
	if(b!=NULL)
	{
		pa->next=b;	
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
	printf("\n");
}



int main()
{
	link *heada,*headb,*m;
	heada=builda();
	headb=buildb();
	print(heada);
	print(headb);
	m=merge(heada,headb);
	printf("-----------------------\n");
	print(m);
}








