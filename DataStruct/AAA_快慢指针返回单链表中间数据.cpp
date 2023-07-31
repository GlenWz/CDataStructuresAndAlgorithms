#include <stdio.h>
#include <stdlib.h> 
typedef struct d {
	int data;
	struct d *next;
}node;

node *builda()
{
	node *head=(node *)malloc(sizeof(node));
	node *ret=head;
	head->data=NULL;
	for(int i=0;i<10;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i+i;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *findMid(node *s)
{
	node *midp,*latp,*ret;
	midp=latp=s->next;
	for(latp;latp;latp=latp->next)
	{
		midp=midp->next;
		latp=latp->next;
	}
	ret=midp;
	return ret;
}
void Print(node *h)
{
	for(h;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}


int main()
{
	node *s=builda();
	Print(s->next);
	node *ss=findMid(s);
	printf("%d->\n",ss->data);
	Print(ss);
}
