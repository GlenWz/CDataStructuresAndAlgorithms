#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data ;
	struct d *next;
}sl;

sl *build()
{
	sl *head;
	sl *p1=(sl*)malloc(sizeof(sl));
	sl *p2=(sl*)malloc(sizeof(sl));
	head=p1;p1->next=p2;p2->next=NULL;
	p1->data=1;p2->data=2;
	return head;
}





int main()
{
	sl *head,*q;
	head=build();
	for(q=head;q;q=q->next)
	{
		printf("%d\n",q->data);
	}
	return 0;
}
