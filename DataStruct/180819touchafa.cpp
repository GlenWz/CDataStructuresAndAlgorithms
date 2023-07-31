#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *build()
{
	link *head,*p;
	head=NULL;
	
	for(int i=0;i<8;i++)
	{
		p=(link *)malloc(sizeof(link));
		p->next=head;
		p->data=i+i;
		head=p;
	}
	return p;
}
void print(link *h)
{
	for(;h;h=h->next)
	{
		printf("%d\n",h->data);
	}
}

int main()
{
	link *s=build();
	print(s);
}
