#include <Stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct d{
	int data;
	struct d *next;
}node;

node *build()
{
	int queue[]={1,3,6,9,8,7,-6,20,-20,18,-7,3,14,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=0;i<rear;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=queue[front++];
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *DEL(node *head)
{
	int v;
	node *a[20];				//这个东西是指针数组啊！ 
	node *ret=head;
	node *p,*q;
	p=head;
	q=head->next;
	node *s2=(node *)malloc(sizeof(node));
	s2->data=-8;
	s2->next=NULL; 
	node *s5;
	for(int i=0;i<20;i++)
	{
	//	a[i]->data=-1;			//你这里给指针数组赋值？？？？ 
		a[i]=s5;
	}
	for(;q!=NULL;p=q,q=q->next)
	{
		v=q->data;
		if(v<0)
		{
			v*=(-1);
		}
		if(a[v]==s5)
		{
			a[v]=s2;
		}else if(a[v]!=s5)
		{
			a[v]=p;
		}
	}
	node *tmp,*p1;
	for(int i=0;i<MAX;i++)
	{
		if(a[i]!=s2||a[i]!=s5)
		{
			p1=a[i];
			tmp=p1->next;
			node *f=tmp;
			p1->next=tmp->next;
			tmp=p1;
			free(f);
		}
	}
	return ret;
}
void Print(node *s)
{
	node *h=s;
	for(h=h->next;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}

int main()
{
	node *s1=build();
	Print(s1);
	node *s2=DEL(s1);
	Print(s2);
}
