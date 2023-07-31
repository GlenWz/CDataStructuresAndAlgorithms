#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *build()
{
	int num;
	printf("please input the V:");
	scanf("%d",&num);
	if(num==-1)
	{
		return NULL;
	}else 
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=num;
		s->next=build();
	}
}
void printL(link *head)
{
	link *h;
	for(h=head;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}
link *insertq(link *head,int v,int pos)
{
	link *p,*q,*h;
	link *ins=(link *)malloc(sizeof(link));
	ins->data=v;
	ins->next=NULL;
	int i=1;
	h=head;
	for(p,q=head;q;++i,p=q,q=q->next)
	{
		if(i==pos)
		{
			p->next=ins;
			ins->next=q;
			p=ins;
		}
	}
	return h;
}

link *Del(link *head,int pos)
{
	link *h,*f,*q,*p;
	int i=1;
	h=head;
	for(p,q=head;q;p=q,q=q->next,i++)
	{
		if(i==pos)
		{
			p->next=q->next;
			f=q;
			q=p->next;
		}
	}
	free(f);
	return h;
}




int main()
{
	link *head,*Insl,*Insq,*del;
	head=build();
	printL(head);
	int pos=3;
	int v=999;
	Insq=insertq(head,v,pos);
	printL(Insq);
	del=Del(Insq,pos);
	printf("---------------------------\n");
	printL(del);
}






