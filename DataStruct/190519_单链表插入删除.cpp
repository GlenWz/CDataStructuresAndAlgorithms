#include <Stdio.h>
#include <Stdlib.h>
#define len 10
typedef struct d{
	int data;
	struct d *next;
}node;

node *find(node *head,int pos)
{
	node *s=head;
	int i=0;
	while(s->next!=NULL&&i<pos)
	{
		s=s->next;
		i++;
	}
	return s;
}

node *builda()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=0;i<len;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*i;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *Insert(node *head,int x,int pos)
{
	node *ret=head;
	if(pos==1)
	{
		node *s=(node *)malloc(sizeof(node));
		head->next=s;
		s->next=NULL;
		s->data=x;
	}
	node *pof=find(ret,pos-1);
	if(pof!=NULL)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=x;
		s->next=pof->next;
		pof->next=s;
	}else 
	{
		printf("error!");
		
	}
	return ret;
}
node *Del(node *head,int pos)
{
	node *ret=head;
	if(pos>len||pos<1)
	{
		printf("error!");
		return NULL;
	}else 
	{
		node *ps=find(head,pos-1);
		node *s=find(head,pos);
		ps->next=s->next;
		free(s);
	}
	return ret;
}
void Print(node *head)
{
	node *h=head;
	for(h=h->next;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}


int main()
{
	node *a=builda();	
	int x=888;
	int pos=5;
	node *aa=Insert(a,x,pos);
	Print(aa);
	node *aaa=Del(aa,pos+1);
	Print(aaa);
}
