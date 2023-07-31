#include <stdio.h>
#include <stdlib.h>

//danlianbiao
typedef struct p{
	int data;
	struct p *next;
}player;

player *build()
{
	player *p1=(player *)malloc(sizeof(player));
	player *p2=(player *)malloc(sizeof(player));
	player *p3=(player *)malloc(sizeof(player));
	player *head,*q,*p;
	int i=0;
	head=p1;p1->next=p2;p2->next=p3;p3->next=NULL;
	for(q=head;q;q=q->next,i++)
	{
		q->data=i;
	}
	return head;
}

player *Del()
{
	player *q,*p,*head;
	head=build();
	for(q=head,p=NULL;q;p=q,q=q->next)
	{
		if(q->data==1)
		{
			if(p)
			{
				p->next=q->next;
				free(q);
				break;
			}
			else
			{
				head=q->next;
			}
		}
	}
	return head;
}

player *Ins()
{
	player *head,*q,*p;
	player *p5=(player *)malloc(sizeof(player));
	head=Del();
	for(q=head,p=NULL;q;p=q,q=q->next)
	{
		if(q->data==2)
		{
			if(q)
			{
				p->next=p5;
				p5->data=5;
				p5->next=q;
				break;
			}
			else
			{
				head=q->next;
			}
		}
		
	}
	return head;
}



int main()
{
	player *head,*q,*p;
	head=build();
	for(q=head;q;q=q->next)
	{
		printf("%d\n",q->data);
	}
	player *del;
	del=Del();
	for(p=del;p;p=p->next)
	{
		printf("del:%d\n",p->data);
	}
	player *ins,*s;
	ins=Ins();
	for(s=ins;s;s=s->next)
	{
		printf("ins:%d\n",s->data);
	}
	while(head!=NULL)
	{
		player *f;
		f=head;
		head=head->next;
		free(f);
	}
}
