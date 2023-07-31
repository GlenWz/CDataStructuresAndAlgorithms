#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct play{
	int ac;char name[10]={};
	struct play *next;
}player;

player *build(void)
{
	player *p1=(player*)malloc(sizeof(player));
	player *p2=(player*)malloc(sizeof(player));
	player *p3=(player*)malloc(sizeof(player));
	player *head;                          //********这个head定义为*（指针）就不要->next了！！！！！！！！！！！！！！！！！！！！！！！！！ 
	head=p1;p1->next=p2;                   //**************head =p1； 
	p2->next=p3;p3->next=NULL;
	p1->ac=1;p2->ac=2;p3->ac=3;
	strcpy(p1->name,"goutou");
	strcpy(p2->name,"sige");
	strcpy(p3->name,"jiansheng");
	return head;
}

int main()
{
	player *head;
	head=build();
	player *q=head;
	for(int i=0;i<3;i++)
	{
		printf("ac is %d ,name is %s\n",q->ac,q->name);
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
