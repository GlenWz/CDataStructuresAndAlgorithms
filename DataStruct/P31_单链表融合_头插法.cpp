#include <Stdio.h>
#include <Stdlib.h>

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
		s->data=x-i*i;
		s->next=head;
		head=s;
	}
	return head;
}
void seravsal(link *h)
{
	for(h;h;h=h->next)
	{
		printf("%d\t",h->data);
	}
	printf("\n----------------------------------\n");
}
link *merge(link *a,link *b)
{
	link *h1=a;
	link *h2=b;
	link *head=(link *)malloc(sizeof(link));
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
	head->next==NULL;
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


int main()
{
	int x=20,y=30;
	link *a=build(x);
	link *b=build(y);
	printf("the link a is :  ");
	seravsal(a);
	printf("the link b is :  ");
	seravsal(b);
	link *me=merge(a,b);
	seravsal(me->next);
	return 0;
}
