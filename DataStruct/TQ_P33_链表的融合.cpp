#include <Stdio.h>
#include <Stdlib.h>
#define len 10
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
		node *s=(node *)malloc(sizeof(node ));
		s->data=rand();
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *buildb()
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
node *Sort_Start(node *h)
{
	// 不要用函数里面的链表进行直接运算 
	node *ret=h;
	node *p,*q,*head;
	for(int i=0;i<len;i++) // 这里必须用计数来进行遍历，用指针来进行遍历容易出错 
	{
		for(head=h,p=head->next,q=p->next;q!=NULL;)
		{
			if(q->data>p->data)
			{
				p->next=q->next;
				q->next=p;
				head->next=q;
				head=head->next;
				q=p->next;
			}else 
			{
				head=head->next;
				p=p->next;
				q=q->next;
			}
		}
	}
	return ret;
}
void Print(node *head)
{
	node *h;
	for(h=head->next;h!=NULL;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}
node *Merge(node *a,node *b)
{
	node *ret=a;
	node *pa=a;
	a=a->next;
	node *pb=b;
	b=b->next;
	while(a!=NULL&&b!=NULL)
	{
		if(a->data>b->data)
		{
			pa=a;
			a=a->next;
		}else if(a->data<b->data)
		{
			pa->next=b;
			pb->next=b->next;
			b->next=a;
			pa=pa->next;
			b=pb->next;
		}else 
		{
			node *s=b;
			pb->next=b->next;
			b=pb->next;
			pa=a;
			a=a->next;
			free(s);
		}
	}
	return ret;
}

int main()
{
	node *a=builda();
	node *b=buildb();
	node *SA=Sort_Start(a);
	node *SB=Sort_Start(b);
	Print(SA);
	Print(SB);
	printf("\n--fgx---\n");
	node *Sab=Merge(SA,SB); 
	Print(Sab);
	
}
