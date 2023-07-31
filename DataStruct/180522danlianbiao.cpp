#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct play{
	int ac;
	char name[10]={};
	struct play *next;
}player;

play *build(void)
{
	player *p1=(player*)malloc(sizeof(player));
	player *p2=(player*)malloc(sizeof(player));
	player *p3=(player*)malloc(sizeof(player));
	p1->ac=1;
	strcpy(p1->name,"goutou");
	p2->ac=2;
	strcpy(p2->name,"sige");
	p3->ac=3;
	strcpy(p3->name,"JS");
	player *head=p1;
	p1->next=p2;
	p2->next=p3;
	p3->next=NULL;
	return head;
	
}


int main()
{
	player *head; int i=0;
	head=build();
	printf("the first play is %s",head->name);
	while(head != NULL)
	{
		player *p = head;
		head = head->next;
		free(p);
		printf("\n%d",++i);
	}
	return 0;
	
}
