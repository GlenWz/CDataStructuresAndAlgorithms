#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *build()
{
	int num;
	printf("shuru");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=num;
		s->next=build();
	}
}

link *nizhi(link *head)
{
	link *now ,*old,*tmp;
	now=head;
	old=now->next;
	for(int i=0;i<5;i++)
	{
		tmp=old->next;
		old->next=now;
		now=old;
		old=tmp;
	}
	head->next->next=tmp;
	return now;
}
void print(link *head)
{
	link *h;
	for(h=head;h;h=h->next)
	{
		printf("%d\n",h->data);
	}
}

int main()
{
	link *head=build();
	link *h=(link *)malloc(sizeof(link));
	h->data=NULL; h->next=head;
	link *s=nizhi(h);
	print(s);
}
