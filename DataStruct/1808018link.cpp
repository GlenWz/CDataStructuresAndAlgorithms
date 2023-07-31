#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *creat()
{
	link *head=(link *)malloc(sizeof(link));
	link *realhead;
	realhead->next=head;
	head->data=NULL;
	head->next=NULL;
	int x=50;
	for(int i=0;i<10;i++,x--)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=x;
		s->next=NULL;head->next=s;
		head=s;
	}
	
	
}
void bianli(link *ss)
{
	link *s=ss->next;
	for(s;s;s=s->next)
	{
		printf("%d\n",s->data);
	}
	printf("\n----------------------------\n");
}




int main()
{
	link *s=creat();
	bianli(s);
	
}
