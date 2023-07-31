#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct play{
	int ac; char name[10]={}; struct play *next;
}player;
play *build(void)
{
	player *p1=(player*)malloc(sizeof(player));
	player *p2=(player*)malloc(sizeof(player));
	player *p3=(player*)malloc(sizeof(player));
	player *head;
	head=p1;int i=0;
	p1->next=p2;
	p2->next=p3;
	p3->next=NULL;
	player *p=head;
	for(i=0;i<3;i++)
	{
		p->ac=i;
		printf("%d\t",p->ac);
		p=p->next; 
	}
	player *q=head;
	for(i=0;i<3;i++)
	{
		strcpy(q->name,"sss");
		printf("\n%s\t\n",q->name);
		q=q->next;
	}
	return head;
}
int main()
{
	player *head;
	head=build();
	player *q=head;
	for(int i=0;i<3;i++)
	{
		printf("name is %s ,ac is %d\n",q->name,q->ac);
		q=q->next;
	}
	
	while(head!=NULL)
	{
		player *p=head;
		head=head->next;
		free(p);
	}
	return 0;
	
}
