#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d* next;
}link;

link *build(int x)
{
	link *head;
	head=NULL;
	for(int i=0;i<5;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=(x-=5);
		s->next=head;
		head=s;
	}
	return head;
}
link *subtraction(link *h1,link *h2)
{
	link *sa=(link *)malloc(sizeof(link));
	link *a=h1,*pa;
	link *b=h2,*pb;
	link *ret;
	ret=sa;
	for(pb=NULL;a!=NULL&&b!=NULL;)
	{
		link *tmp;
		if(a->data==b->data)
		{
			tmp=b;
			b=b->next;
			free(tmp);
		}
		else if(a->data>b->data)
		{
			sa->next=b;
			sa=sa->next;
			pb=b;
			b=b->next;
		}else if(a->data<b->data)
		{
			sa->next=a;
			sa=sa->next;
			a=a->next;
		}
	}
	sa->next=NULL;
	if(a!=NULL)
	{
		sa->next=a;
	}
	if(b!=NULL)
	{
		sa->next=b;
	}
	return ret;
	
}

void print(link *h)
{
	for(h;h;h=h->next)
	{
		printf("%d\t",h->data);
	}
	printf("\n-------------------------------------\n");
}


int main()
{
	int x,y;
	x=50;y=40;
	link *a=build(x);
	link *b=build(y);
	print(a);
	print(b);
	link *sub=subtraction(a,b);
	print(sub->next);
} 
