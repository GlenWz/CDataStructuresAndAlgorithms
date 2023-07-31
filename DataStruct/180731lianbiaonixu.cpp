#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *build()
{
	int num; int x=1;
	link *head=(link *)malloc(sizeof(link));
	link *rear=(link *)malloc(sizeof(link));
	head->next=rear;head->data=NULL;
	rear->next=head;rear->data=NULL;
	printf("how many?");
	scanf("%d",&num);
	for(int i=0;i<num;i++,x+=3)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=x;s->next=head;
		rear->next=s;
		rear=s;
	}
//	rear->next=NULL;
	return head->next;
}
link * nixu(link *head)
{
	link *now,*old,*tmp;
	now=head->next;
	old=now->next;
	for(int i=0;i<8;i++)
	{
		tmp=old->next;
		old->next=now;
		now=old;
		old=tmp;
	}
	head->next->next=tmp;
	return now;
}

void bianli(link *head)
{
	link *h;
	for(h=head;h->data;h=h->next)
	{
		printf("%d\n",h->data);
	}
	printf("---------------end\n");
}

int main()
{
	link *head=build();
	bianli(head->next);
	link *s=nixu(head);
	bianli(s);
}
