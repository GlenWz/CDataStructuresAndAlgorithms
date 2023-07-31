#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
	struct d *pre;
	int Freq;
}node;

node *build()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=1;i<10;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i;
		s->Freq=0;
		head->next=s;
		s->pre=head;
		head=s;
	}
	head->next=ret;
	ret->pre=head;
	return ret;
}
void PrintN(node *head)
{
	node *h;
	for(h=head->next;h->data!=NULL;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}
void PrintP(node *head)
{
	node *h;
	for(h=head->pre;h->data!=NULL;h=h->pre)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}
node *Change(node *head)
{
	node *lp,*rp,*lh,*rh,*ret;
	ret=head;
	rh=head->next;
	lh=head->pre;
	lp=head;
	rp=head;
	int i;
	for(i=1;i<10;i++)
	{
		if(i%2==1)
		{
			rp=rh;
			rh=rh->next;
		}else 
		{
			rp->next=rh->next;
			rh->next->pre=rp;
			rh->next=lp;
			rh->pre=lh;
			lp->pre=rh;
			lh->next=rh;
			rh=rp->next;
			lp=lp->pre;
			lh=lp->pre;
		}
	}
	
	return ret;
}

node *Locate(node *head,int n,int &pos)
{
	node *h,*hp,*ret,*q;
	ret=head;
	h=head->next;
	hp=head->next;
	pos=0;
	for(;h!=NULL&&h->data!=n;)
	{
		h=h->next;
		pos++;
	}
	h->Freq++;
	if(h==NULL)
	{
		printf("NOT FIND!\n");
		return NULL;
	}
	q=h->pre;
	while(q->Freq<=h->Freq&&q->data!=NULL)
	{
		q=q->pre;
	}
	if(q!=h->pre)
	{
		h->pre->next=h->next;
		h->next->pre=h->pre;
		q->next->pre=h;
		h->next=q->next;
		q->next=h;
		h->pre=q;
	}
	
	
	return ret;
}

int main()
{
	node *h=build();
	PrintN(h);
	PrintP(h);
	node *h1=Change(h);
	PrintN(h1); 
	int pos=-1;
	node *F1=Locate(h,8,pos);
	PrintN(F1);
	node *F2=Locate(h,6,pos);
	PrintN(F2);
	node *F3=Locate(h,6,pos);
	PrintN(F3);
	node *F4=Locate(h,6,pos);
	PrintN(F4);
	node *F5=Locate(h,8,pos);
	PrintN(F5);
}
