#include <Stdio.h>
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
		link *s=(link *)malloc(sizeof(link*));
		s->data=num;
		s->next=build();
	}
}


link *chong(link *head)
{
	link *h,*q;
	h=head;
	while(h->next!=NULL)
	{
		if(h->data==h->next->data)
		{
			q=h->next;
			h->next=q->next;
			free(q);
		}else
		{
			h=h->next;
		}
	}
	return head;
}

void pint(link *head)
{
	link *h=head;
	for(;h;h=h->next)
	{
		printf("%d\n",h->data);
	}
	printf("------------end\n");
}




int main()
{
	link *head=build();
	pint(head);
	link *s=chong(head);
	pint(s);
}
