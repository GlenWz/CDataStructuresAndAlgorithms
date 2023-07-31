#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link * build(int x)
{
	link *head;
	head=NULL;
	for(int i=0;i<5;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=x-=5;
		s->next=head;
		head=s;
	}
	return head;
}
link *merge(link *a,link *b)
{
	link *head=(link *)malloc(sizeof(link));
	link *h1=a,*h2=b;
	link *ret=head;
	while(h1!=NULL&&h2!=NULL)
	{
		if(h1->data>h2->data)
		{
			head->next=h2;
			h2=h2->next;
			head=head->next;
		}else 
		{
			head->next=h1;
			h1=h1->next;
			head=head->next;
		}
	}
	head->next=NULL;
	if(h1!=NULL)
	{
		head->next=h1;
	}
	if(h2!=NULL)
	{
		head->next=h2;
	}
	return ret;
}

link *sub(link *h,link *s)
{
	link *head,*ph;
	head=h;
	ph=h;
	h=h->next;
//	printf("%d\t",h->data);
	while(h!=NULL&&s!=NULL)
	{
		link *tmp;
		if(h->data==s->data)
		{
			tmp=h;
			ph->next=h->next;
			h=h->next;
			s=s->next;
			free(tmp);
		}else if(h->data<s->data)
		{
			ph=h;
			h=h->next;
		}else 
		{
			s=s->next;
		}		
	}
	return head;	
}

void print(link *h)
{
	for(h;h;h=h->next)
	{
		printf("%d\t",h->data);
	}
	printf("\n---------------------------------------------x\n");
}

int main()
{
	link *b=build(50);
	link *a=build(30);
	print(a);
	link *m=merge(a,b);
	print(m->next);
	link *c=sub(m,b);

	print(c->next);
	return 0;
}
