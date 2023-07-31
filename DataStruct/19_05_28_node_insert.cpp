#include <Stdio.h>
#include <Stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}node;

node *builda()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=0;i<10;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*i;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *Del(node *head,int pos)
{
	node *h,*ph,*ret,*tmp;
	h=ph=ret=head;
	int count=1;
	for(h=h->next;h;ph=h,h=h->next)
	{
		if(pos==count)
		{
			tmp=h;
			h=h->next;
			ph->next=h;
			free(tmp);
		}
		count++;
	}
	return ret;
}
node *Print(node *head)
{
	node *h;
	for(h=head->next;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}


int main()
{
	node *a=builda();
	Print(a);
	node *del=Del(a,8);
	Print(del);
}
