#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct play{
	int ac;char name[10]={};
	struct play *next;
}player;

player * build()
{
	player *p1=(player *)malloc(sizeof(player));
	player *p2=(player *)malloc(sizeof(player));
	player *p3=(player *)malloc(sizeof(player));
	player *p,*head;
	head=p1;
	p1->next=p2;p2->next=p3;
	p3->next=NULL;
	int i;
	for(p=head,i=1;p;p=p->next,i++)
	{
		p->ac=i;
	}
	strcpy(p1->name,"sige");
	strcpy(p2->name,"goutou");
	strcpy(p3->name,"jiansheng");
	return head;
}

player * Deletechain()
{
	player *head,*p,*q;
	head=build();
	for(p=head,q=NULL;p;q=p,p=p->next)
	{
		if(p->ac==2)
		{
			if(q)
			{
				q->next=p->next;
			}
			else
			{
				head=p->next;
			}
			free(p);
		}
	}
	return head;
}

int main()
{
	player *head,*p,*del,*q;
	head=build();
	for(p=head;p;p=p->next)
	{
		printf("%s-----%d\n",p->name,p->ac);
	}
	del=Deletechain();
	for(q=del;q;q=q->next)
	{
		printf("%s----%d\n",q->name,q->ac);
	}
	for(p=head;head;head=head->next)
	{
		free(p);
	}
	return 0;






























	
}
