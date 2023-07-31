#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct play{
	int ac;char name[10]={};
	struct play *next;
}player;

player *build(void)
{
	player *p1=(player*)malloc(sizeof(player));
	player *p2=(player*)malloc(sizeof(player));
	player *p3=(player*)malloc(sizeof(player));
	
	player *head=p1;
	p1->next=p2;p2->next=p3;
	p3->next=NULL;
	player *q=head;
	for(int i=1;i<4;i++)
	{
		q->ac=i;
		printf("%d",q->ac);
		q=q->next;
	}
	strcpy(p1->name,"GT");
	strcpy(p2->name,"SG");
	strcpy(p3->name,"JS");
    return head;
}
int main()
{
	player *head;
	head=build();
	player *q=head;
	for(int i=0;i<3;i++)
	{
		printf("the name is %s,ac is %d\n",q->name,q->ac);
		q=q->next;
	}
	while(head!=NULL)
	{
		player *f=head;
		head=head->next;
		free(f);
	}
	return 0;
	
}
