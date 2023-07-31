#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link* findth(link *head,link *m);
link *build()
{
	int num;
	printf("please input");
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

link *delmin(link *head)
{
	link *h=head;
	link *p=h->next,*minp=p,*min=h;
	while(p!=NULL)
	{
		if(p->data<minp->data)
		{
			minp=p;
			min=h;
		}
		h=p;
		p=p->next;
	}
	min->next=minp->next;
	free(minp);
	return head;
}

void bianli(link *head)
{
	link *h=head->next;
	for(h;h;h=h->next)
	{
		printf("%d\n",h->data);
	}
	printf("--------------end\n");
}




int main()
{
	link *head=build();
	link *h=(link *)malloc(sizeof(link));
	h->data=NULL; h->next=head;
	bianli(h);
	link *s=delmin(h);
	bianli(s);
}
