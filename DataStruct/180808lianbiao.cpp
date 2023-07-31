#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data ;
	struct d *next;
}link;

link *build()
{
	link *head=(link *)malloc(sizeof(link));
	link *rear=(link *)malloc(sizeof(link));
	head->next=rear;rear->next=head;
	head->data=NULL;rear->data=NULL;
	for(int i=0;i<5;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->next=head;s->data=i+i;
		rear->next=s;
		rear=s;
	}
 	link *h=head;
 
 	head=head->next;
 		h->next=NULL;
	return head;
}






void schu(link *h)
{
	link *s=h->next;
	for(s;s;s=s->next)
	{
		printf("%d\t",s->data);
	}
}



int main()
{
	link *h=build();
	schu(h->next);

}
