#include <stdio.h>

typedef struct player{
	int ac;char name[20];int hp;int power; int IQ;
	struct player *next;
}play;

int main()
{
	play p1={1,"goutou",5000,300,50};
	play p2={2,"sige",4000,800,150};
	play p3={3,"js",3000,600,120};
	play *head;
	head=&p1;
	p1.next=&p2;
	p2.next=&p3;
	p3.next=NULL;
	printf("the first player is %s",head->name);
	return 0;
}
