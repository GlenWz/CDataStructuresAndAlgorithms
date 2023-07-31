#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct play{
	int ac; char name[10];
	struct play *next;
}player;

player *build(void)
{
	player *p1=(player *)malloc(sizeof(player));
	player *p2=(player *)malloc(sizeof(player));
	player *p3=(player *)malloc(sizeof(player));
	
	p1->ac=1;p2->ac=2;
	p3->ac=3;
	strcpy(p1->name,"GT");
	strcpy(p2->name,"SG");
	strcpy(p3->name,"JS");
	player *head;
	head=p1;
	p1->next=p2;
	p2->next=p3;
	p3->next=NULL;
	return head;
}


int main()
{
	player *head;
	head=build();
	player *s=head;
	for(int i=0;i<3;i++)
	{
		printf("the name is %s,%d\n",s->name,s->ac);
		s=s->next;
	}
	printf("%s\n",head->name);
	while(head!=NULL)
	{
		player *d=head;
		head=head->next;
		free(d);
	}
	return 0;
	
}
