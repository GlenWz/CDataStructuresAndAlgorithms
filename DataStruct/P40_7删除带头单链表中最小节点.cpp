#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}node;

node *build()
{
	int num;
	printf("shuru");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=num;
		s->next=build();
	}
}

node *del(node *head)
{
	node *h=head,*p=head->next;
	node *minp=p,*min=h;
	for(;p;p=p->next)
	{
		
		if(p->data<minp->data)
		{
			minp=p;
			min=h;
		}
		h=h->next;
	}
	min->next=minp->next;
	free(minp);
	return head;
}

void bianli(node *head)
{
	node *h=head->next;
	for(;h;h=h->next)
	{
		printf("%d\n",h->data);
	}

}


int main()
{
	node *h=build();
	node *head=(node *)malloc(sizeof(node));
	head->next=h;head->data=NULL;
	node *s=del(head);
	bianli(s);
}
