#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct play{
	int ac;char name[10]={};
	struct play *next;
}player;

player *build()
{
	player *p1=(player*)malloc(sizeof(player));
	player *p2=(player*)malloc(sizeof(player));
	player *p3=(player*)malloc(sizeof(player));
	player *head=p1;
	p1->next=p2;p2->next=p3;p3->next=NULL;
	player *q=head;
	int i;
    for(i=1;i<4;i++)
    {
    	q->ac=i;
    	q=q->next;
	}
	strcpy(p1->name,"goutou");
	strcpy(p2->name,"sige");
	strcpy(p3->name,"jiansheng");
	return head;
}


int main()
{
	player *head,*q,*p;
	head=build();
	p=head;
	while(p!=NULL)
	{
		printf("the name is %s ,and the ac is %d\n",p->name,p->ac);
		p=p->next;
	}
	while(head!=NULL)
	{
		q=head;
		head=head->next;
		free(q);
	}
	return 0;
}
