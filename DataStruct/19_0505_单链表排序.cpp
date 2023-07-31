#include <Stdio.h>
#include <stdlib.h>
#define len 11

typedef struct d{
	int data;
	struct d *next;
}link;

link *builda()
{
	link *head=(link *)malloc(sizeof(link));
	link *ret=head;
	head->data=NULL;
	for(int i=0;i<len;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->next=NULL;
		head->next=s;
		s->data=i*i;
		head=s;
	}
	return ret;
}
link *buildb()
{
	link *head=(link *)malloc(sizeof(link));
	head->data=NULL;
	link *ret=head;
	for(int i=0;i<len;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->next=NULL;
		s->data=i+i;
		head->next=s;
		head=s;
	}
	return ret;
}
link *Sort_Start(link *h)
{
	//交换指针域 
	link *ret=h;
	link *tmp,*p,*q,*head;
	for(int i=0;i<len;i++)
	{
		for(head=h,p=head->next,q=p->next;q!=NULL;) //初始化必须放for里面 
		{
			if(p->data>q->data)
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
 
link *sort(link *h)
{
	//变换数据域 ，冒泡排序 
	link *ret=h;
	link *p,*i,*q;
	int mid;
	for(i=h->next;i!=NULL;i=i->next)
	{
		for(p=h->next,q=p->next;q!=NULL;p=q,q=q->next)
		{
			if(p->data>q->data)
			{
				mid=p->data;
				p->data=q->data;
				q->data=mid;
			}
		}
	}
	return ret;
}


void Print(link *head)
{
	link *h;
	for(h=head->next;h!=NULL;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}

int main()
{
	link *a=builda();
	link *b=buildb();
	link *sa=sort(a);
//	link *sb=sort(b);
	link *c=buildb();
	link *cc=Sort_Start(c);
	Print(a);
	Print(b);
	Print(sa);
	printf("the c:\n");
	Print(c);
	printf("\nCC:\n");
	Print(cc);
	
}










