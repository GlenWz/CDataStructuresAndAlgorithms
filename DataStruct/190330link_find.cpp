#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *find(link *head,int pos)
{
	int i=1;
	link *q;
	for(q=head;q;q=q->next,i++)
	{
		if(i==pos)
		{
			return q;
		}
	}
	
}

link *build()
{
	int num;
	printf("please input the NUN:\n");
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
void print(link *head)
{
	link *h;
	for(h=head;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}
link *insert(link *head,int v,int pos)
{
	link *h=head;
	link *p=find(h,pos);
	link *ins=(link *)malloc(sizeof(link));
	ins->data=v;
	ins->next=p->next;
	p->next=ins;
	return h;
}
link *Del(link *head,int pos)
{
	link *h=head;
	link *p,*q;
	p=find(h,pos-1);
	q=find(h,pos);
	p->next=q->next;
	free(q);
	return h;
}

int main()
{
	link *head,*Insert,*del;
	head=build();
	print(head);
	int v=99;
	int pos=3;
	Insert=insert(head,v,pos);
	print(Insert);
	del=Del(Insert,pos);
	printf("--------------------\n");
	print(del);
	
}
