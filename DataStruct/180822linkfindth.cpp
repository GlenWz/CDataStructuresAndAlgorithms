#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct d{
	int data;
	struct d *next;
}link;
clock_t start, stop;
double duration;
link *findth(link *h,int pos);
link *initiative()
{
	link *head;
	head=NULL;
	int x=5;
	for(int i=0;i<10000;i++)
	{
		/*printf("please input the v:");
		scanf("%d",&x);*/
		link *s=(link *)malloc(sizeof(link));
		s->data=x*i;
		s->next=head;
		head=s;
	}
	return head;
}
link *insert(link *s,int pos,int x)
{
	int i=1;
	link *h=(link *)malloc(sizeof(link));
	h->data=x;
	link *p,*f;
	if(pos==1)
	{
		h->next=s;
		return s;
	}else 
	{
		f=findth(s,pos);
		p=findth(s,pos-1);
		h->next=f;
		p->next=h;
		return s;
	}
}
link *findth(link *h,int pos)
{
	link *s;
	for(int i=1;h;i++,h=h->next)
	{
		if(pos==i)
		{
			s=h;
			return s;
		}
	}
	printf("no find!\n");
	return NULL;
}
void traversal(link *h)
{
	for(h;h;h=h->next)
	{
		printf("%d\t",h->data);
	}
	printf("\n----------------------------------------\n");
}
link *DEL(link *h,int pos)
{
	int i=1;
	link *p,*f;
	f=findth(h,pos);
	p=findth(h,pos-1);
	p->next=f->next;
	free(f);
	return h;
}


int main()
{
	start = clock();
	link *l=initiative();
	traversal(l);
	int pos=3;int x=888;
	link *i=insert(l,pos,x);
	traversal(i);
	link *del=DEL(i,pos+2);
	traversal(del);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK;
	printf("%lf\n",duration);
	return 0;
}
