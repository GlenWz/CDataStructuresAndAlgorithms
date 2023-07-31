#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct play{
	int account;char name[10];
	struct play *next;
}player;

player *build(void)
{
	player *p1=(player *)malloc(sizeof(player));
	player *p2=(player *)malloc(sizeof(player));
	player *p3=(player *)malloc(sizeof(player));
	if(p1!=NULL)
	{
		p1->account=1;
		strcpy(p1->name,"goutou");
		p2->account=2;
		strcpy(p2->name,"sige");
		p3->account=3;
		strcpy(p3->name,"js");
		play *head;
		head=p1;
		p1->next=p2;
		p2->next=p3;
		p3->next=NULL;
	return head;	
	}
	
}

int main()
{
	play *head;
	head=build();
	printf("the first player is :%s",head->name);
	return 0;
	
}
