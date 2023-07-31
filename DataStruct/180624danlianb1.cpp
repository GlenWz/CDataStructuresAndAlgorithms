#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct play
{
	int ac; char name[10]={};
	struct play *next;
}player;

player *build()
{
	player *p1=(player *)malloc(sizeof(player));
	player *p2=(player *)malloc(sizeof(player));
	player *p3=(player *)malloc(sizeof(player));
	player *head,*q,*p;
	int i=1;
	head=p1; p1->next=p2;
	p2->next=p3;p3->next=NULL;
	for(q=head;q;q=q->next,i++)
	{
		q->ac=i;
	}
	strcpy(p1->name,"sige");
	strcpy(p2->name,"jiansheng");
	strcpy(p3->name,"ruizi");
	return head;
}
player *Del()
{
	player *head,*q,*p;
	head=build();
	for(q=head,p=NULL;q;q=q->next,p=q)
	{
		if(q->ac==2)
		{
			if(p)
			{
				p->next=q->next;
			}
			else
			{
				head=q->next;
			}
			free(q);
			break;
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
		printf("---%s----%d--\n",q->name,q->ac);
	}
	player *del;
	del=Del();
	for(p=del;p;p=p->next)
	{
		printf("---%s----%d--\n",p->name,p->ac);
	}
	while(head!=NULL)
	{
		q=head;
		head=head->next;
		free(q);
	}
	return 0;
}
