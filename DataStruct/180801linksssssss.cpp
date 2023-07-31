#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

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
		//return s;
	}
}

link *chong(link *head)
{
	link *h=head;
	link *p=h->next,*q;
	while(p->next!=NULL)
	{
		if(p->data==p->next->data)
		{
			q=p->next;
			p->next=q->next;
			free(q);
		}else
		{
			p=p->next;
		}
	}
	return h;
}

void print(link *head)
{
	link *h;
	for(h=head;h;h=h->next)
	{
		printf("%d\n",h->data);
	}
	printf("------------------------end\n");
}


int main()
{
	link *head=build();
	print(head);
	link *s=chong(head);
	print(s);
}
