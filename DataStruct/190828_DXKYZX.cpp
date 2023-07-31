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
	for(int i=0;i<17;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i;
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
	for(int i=0;i<7;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*2+1;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *buildc()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=1;i<5;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*2;
		s->next=NULL;
		head->next=s;
		head=s;
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
node *MergeC(node *a,node *b)
{
	node *pa,*pb,*q,*fb,*lb,*ret;
	pa=a;
	ret=pa;
	pb=b;
	a=a->next;
	fb=b->next;
	b=b->next;
	for(;b;b=b->next)
	{
		if(b->next==NULL)
		{
			lb=b;	
		}
	}
	for(;a;)
	{
		if(a->data<fb->data)
		{
			pa->next=a->next;
			q=a;
			a=pa->next;
			free(q);
		}else 
		{
			if(a->data<=lb->data)
			{
				pa=a;
				a=a->next;
			}else 
			{
				pa->next=NULL;
				break;
			}
		}
		
	}
	for(;a;)
	{
		q=a;
		a=a->next;
		free(q);
	}
	return ret;
}

node *Del(node *a,node *b,node *c)
{
	node *pa,*ret,*q,*ha;
	pa=a;
	ret=pa;
	a=a->next;
	b=b->next;
	c=c->next;
	
	for(;a&&b;)
	{
		if(a->data==b->data)
		{
			pa->next=a->next;
			q=a;
			a=pa->next;
			free(q);
		}else if(a->data<b->data)
		{
			pa=a;
			a=a->next;
		}else if(a->data>b->data)
		{
			b=b->next;
		}
	}
	pa=ret;
	ha=ret->next;
	for(;ha&&c;)
	{
		if(ha->data==c->data)
		{
			pa->next=ha->next;
			q=ha;
			ha=pa->next;
			free(q);
		}else if(ha->data<c->data)
		{
			pa=ha;
			ha=ha->next;
		}else if(ha->data>c->data)
		{
			c=c->next;
		}
	}
	
	
	return ret;
}



int main()
{
	node *a=builda();
	node *b=buildb();
	node *c=buildc();
	Print(a);
	Print(b);
	Print(c);
	//node *ba=MergeC(a,b);
	//Print(ba);
	node *abc=Del(a,b,c);
	Print(abc);
}














