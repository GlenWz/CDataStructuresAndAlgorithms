#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct play{
	int ac; char name[10]={};
	struct play * next;
}player;

player *build()
{
	player *p1=(player *)malloc(sizeof(player));
	player *p2=(player *)malloc(sizeof(player));
	player *p3=(player *)malloc(sizeof(player));
	player *head,*q,*p; int i=1;
	head=p1;
	p1->next=p2;p2->next=p3;
	p3->next=NULL;
	for(q=head;q;q=q->next,i++)
	{
		q->ac=i;
	}
	strcpy(p1->name,"sige");
	strcpy(p2->name,"jiansheng");
	strcpy(p3->name,"goutou");
	return head;
}
player *Del()
{
	player *head,*q,*p;
	head=build();
	for(q=head,p=NULL;q;p=q,q=q->next)
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
	player *head,*del,*q,*p;
	head=build();
	for(q=head;q;q=q->next)
	{
		printf("---%s----%d--\n",q->name,q->ac);
	}
	del=Del();
	for(q=del;q;q=q->next)
	{
		printf("---%d--%s--\n",q->ac,q->name);
	}
	while(head!=NULL)
	{
		p=head;
		head=head->next;
		free(p);
	}
	return 0;
}
