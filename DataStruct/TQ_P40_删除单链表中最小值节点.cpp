#include <Stdio.h>
#include <stdlib.h>
#define len 10

/* �����Ҳ���������������Ȼ��ɾ����һ���ڵ㣬�����ʱ�临�Ӷ���O(N^2),
��¼�ڵ�ʱ�临�Ӷ�ΪO(n)*/  

typedef struct d{
	int data;
	struct d *next;
}node;

node *builda()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=0;i<len;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=rand();
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
void Print(node *head)
{
	node *h=head;
	for(h=h->next;h!=NULL;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}
node *DelMin(node *head)
{
	node *h,*ph,*p,*qh,*ret;
	int min=9999999;
	ret=h=head;
	for(p=h,h=h->next;h!=NULL;p=h,h=h->next)
	{
		if(h->data<min)
		{
			min=h->data;
			qh=h;
			ph=p;
		}
	}
	node *f=qh;
	ph->next=qh->next;
	qh=ph->next;
	free(f);
	return ret;
	
}

int main()
{
	node *a=builda();
	Print(a);
	node *del=DelMin(a);	
	Print(del);
}
