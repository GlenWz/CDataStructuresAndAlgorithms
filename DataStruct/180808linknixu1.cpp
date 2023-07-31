#include <Stdio.h>
#include <Stdlib.h>
typedef struct d{
	int data;
	struct d *next;
}link;

link *build()
{
	int num;
	printf("please input the V");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else 
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=num;
		s->next=build();
		return s;
	}
}
link *nixu(link *head)
{
	link *h=head;
	link *now,*old,*tmp;
	now=h;
	old=now->next;
	for(h;tmp;h=h->next)
	{
		tmp=old->next;
		old->next=now;
		now=old;
		old=tmp;
	}
	head->next->next=tmp;
	return now;
}
void bianli(link *s)
{
	for(s;s;s=s->next)
	{
		printf("%d\t",s->data);
	}
}




int main()
{
	link *head=build();
	bianli(head);
	link *h=(link *)malloc(sizeof(link));
	h->next=head;h->data=NULL;
	link *s=nixu(h);
	bianli(s);
	
}
