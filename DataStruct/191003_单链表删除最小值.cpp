#include <Stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	struct n *next;
}node;

node *buildn()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	int a[]={3,1,2,5,3,1,2,68,2,5,6,1,2};
	int len=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<len;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->next=NULL;
		s->data=a[i];
		head->next=s;
		head=s;
	}
	return ret;
}

node* DELMIN(node *n)
{
	node *head=n->next,*ret=n,*p,*q,*del; //��ͷ�ڵ�ĵ����� 
	int Min=head->data;
	for(;head;head=head->next)
	{
		if(Min>head->data)
		{
			Min=head->data;
		}
	}
	for(p=ret,q=ret->next;q;p=q,q=q->next)//pΪǰ����qΪp�ĺ�� 
	{
		if(q->data==Min)
		{
			p->next=q->next;
			del=q;
			q=p->next;
			free(del);
		}
	}
	return ret;
}
void Printn(node *n)
{
	node *head;
	for(head=n->next;head;head=head->next)
	{
		printf("%d->",head->data);
	}
	printf("\n");
}
int main()
{
	node *n=buildn();
	Printn(n);
	printf("\n");
	node *n1=DELMIN(n);
	Printn(n1);
}





