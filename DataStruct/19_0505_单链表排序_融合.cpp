#include <Stdio.h>
#include <stdlib.h>
#define len 12

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
		s->data=(3-2*i)*i;
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
		s->data=rand();
		head->next=s;
		head=s;
	}
	return ret;
}
link *Sort_Start(link *h)
{
	//Ωªªª÷∏’Î”Ú 
	link *ret=h;
	link *tmp,*p,*q,*head;
	for(int i=0;i<len;i++)
	{
		for(head=h,p=head->next,q=p->next;q!=NULL;)
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
	//±‰ªª ˝æ›”Ú £¨√∞≈›≈≈–Ú 
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
link *Merge(link *a,link *c)
{
	link *ret=a;
	link *la=a->next;
	link *lc=c->next;
	while(la!=NULL&&lc!=NULL)
	{
		if(la->data>lc->data)
		{
			c->next=lc->next;
			lc->next=la;
			a->next=lc;
			lc=c->next;
			a=a->next;
		}else if(a->data<lc->data) 
		{
			a=la;
			la=la->next;
		}else 
		{
			link *s=lc;
			c->next=lc->next;
			lc=c->next;
			a=la;
			la=la->next;
			free(s);
		}
	}
	
	if(c!=NULL)
	{
		a->next=c;
	}
	return ret;
}

void Print(link *head)
{
	link *h;
	for(h=head->next;h!=NULL;h=h->next)
	{
		printf("%d ",h->data);
	}
	printf("\n");
}

int main()
{
	link *a=builda();
	link *b=buildb();
	Print(a);
	Print(b);
	link *sa=Sort_Start(a);
//	link *sb=sort(b);
	link *c=buildb();
	printf("the c:\n");
	Print(c);
	link *sc=Sort_Start(c);
	
	Print(sa);
	
	printf("CC:\n");
	Print(sc);
	printf("merge later!\n");
	link *AC=Merge(sa,sc);
	printf("the Merge result:\n");
	Print(AC);
}










