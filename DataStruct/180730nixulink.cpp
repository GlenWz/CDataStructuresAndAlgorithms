#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *build()
{
	int num;
	printf("please innput the va");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=num;
		s->next=build();
		return s;
	}
}

void out(link *head)
{
	link *h=head;
	for(;h;h=h->next)
	{
		printf("%d\n",h->data);
	}
}
link *NIXU(link *head)
{
	link *NEW,*OLD,*TMP;
	NEW=head->next;
	OLD=NEW->next;
	int n;
	printf("please input the va");
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		TMP=OLD->next;
		OLD->next=NEW;
		NEW=OLD;
		OLD=TMP;
	}
	head->next->next=TMP;
	return NEW;
}



int main()
{
	link *head=build();
	out(head);
	link *m=(link *)malloc(sizeof(link));
	m->next=head;m->data=NULL;
	link *tou=NIXU(m);
	out(tou);
	
}
