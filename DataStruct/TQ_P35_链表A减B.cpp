#include <Stdio.h>
#include <stdlib.h>
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
		node *s=(node *)malloc(sizeof(node));
		s->data=i*4;
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
		s->data=i*2;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *sort(node *head)
{
	node *ret=head;
	node *ph,*qh,*h;
	for(int i=0;i<len;i++)
	{
		for(h=head,ph=h->next,qh=ph->next;qh!=NULL;)  //这里必须在里面进行赋值 
		{											 // 外面嵌套循环 
			if(ph->data>qh->data)
			{
				ph->next=qh->next;
				qh->next=ph;
				h->next=qh;
				h=h->next;
				qh=ph->next;
			}else if(ph->data<=qh->data)
			{
				h=h->next;
				ph=ph->next;
				qh=qh->next;
			}
		}
	}
	return ret;
}
node *cha(node *ha,node *hb)
{
	node *ret=ha;
	node *pa,*a,*b;
	//排序完之后利用一重循环来进行就够了 
	for(pa=ha,a=pa->next,b=hb->next;ha!=NULL&&b!=NULL;)
		{
			if((a->data)==(b->data))
			{
				node *f=a;
				pa->next=a->next;
				a=pa->next;
				free(f);
				b=b->next;
			}else if(a->data>b->data)
			{
				b=b->next;
				
			}else
			{
				pa=a;
				a=a->next;
			}
		}
	/*
	for(int i=0;i<len;i++)
	{
		for(pa=ha,a=pa->next,b=hb->next;ha!=NULL&&b!=NULL;)
		{
			if((a->data)==(b->data))
			{
				node *f=a;
				pa->next=a->next;
				a=pa->next;
				free(f);
				b=b->next;
			}else if(a->data>b->data)
			{
				b=b->next;
				
			}else
			{
				pa=a;
				a=a->next;
			}
		}
	}*/
	
	return ret;
}


void print(node *head)
{
	node *h;
	for(h=head->next;h!=NULL;h=h->next)
	{
		printf("%d ",h->data);
	}
	printf("\n------------------------------\n");
}
int main()
{
	node *a=builda();
	node *b=buildb();
	print(a);
	print(b); 
	printf("sort!\n");
	node *sa=sort(a);
	print(sa);
	node *sb=sort(b);
	print(sb);
	printf("a-b\n");
	node *a_b=cha(a,b);
	print(a_b);
}





