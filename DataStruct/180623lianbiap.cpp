#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct play{
	int ac; char name[10]={};
	struct play *next;
}player;

player *build()
{
	player *p1=(player *)malloc(sizeof(player));
	player *p2=(player *)malloc(sizeof(player));
	player *p3=(player *)malloc(sizeof(player));
	player *head=p1;
	p1->next=p2;
	p2->next=p3;
	p3->next=NULL;
	player *a;
	int i;
	for(i=1,a=p1;a;a=a->next,i++)
	{
		a->ac=i;
	}
	strcpy(p1->name,"sige");
	strcpy(p2->name,"Goutou");
	strcpy(p3->name,"jiansheng");
	return head;
}

int main()
{
	player *head,*q;
	head=build();
	for(q=head;q;q=q->next)
	{
		printf("----%s-----%d---\n",q->name,q->ac);
	}
	while(head!=NULL)
	{
		player *p;
		p=head;
		head=head->next;
		free(p);
	}
	return 0;
}
