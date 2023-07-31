#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct play{
	int ac; char name[10]={};
	struct play *next;
}player;

player *build()
{
	
	player *head=p1;
	p1->next=p2;p2->next=p3;
	p3->next=NULL;
	player *q=p1;
	for(int i=1;q;q=q->next,i++)
	{
		q->ac=i;
	}
	strcpy(p1->name,"sige");
	strcpy(p2->name,"goutpu");
	strcpy(p3->name,"jiansheng");
	return head;
}

player * Delete()
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
	player *head,*q;
	head=build();
	for(q=head;q;q=q->next)
	{
		printf("%s----%d\n",q->name,q->ac);
	}
	player *del,*p;
	del=Delete();
	for(p=del;p;p=p->next)
	{
		printf("%s----%d--\n",p->name,p->ac);
	}
	while(head!=NULL)
	{
		player *q;
		q=head;
		head=head->next;
		free(q);
	}
	return 0;
}
