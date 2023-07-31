#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *merge(link *pa,link *pb);
link *build(int x)
{
	link *head,*s;
	head=NULL;
	for(int i=0;i<5;i++)
	{
		s=(link *)malloc(sizeof(link));
		s->data=(x-i*2);
		s->next=head;
		head=s;
	}
	return head;
}

void travsal(link *s)
{
	for(s;s;s=s->next)
	{
		printf("%d\t",s->data);
	}
	printf("\n--------------------------------\n");
}

link *merge(link *pa,link *pb)
{
	link *h1=pa;
	link *h2=pb;
	link *head=(link *)malloc(sizeof(link));
	link *ret;
	ret=head;
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

int main()
{
	int x=50,y=50;
	link *a=build(x);
	link *b=build(y);
	travsal(a);
	link *h=merge(a,b);
	travsal(h->next);
	return 0;
}
