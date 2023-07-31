#include <stdio.h>
#include <stdlib.h>
#define len sizeof(Qnode)

typedef struct Qnode{
	int data;
	struct Qnode *next;
}Qnode,*quep;

typedef struct {
	Qnode *front;
	Qnode *rear;
}linkq;

linkq initqueue();
linkq ADDD(linkq head,int x);
void schu(linkq head);


linkq initqueue()
{
	linkq q;
	q.front=q.rear=(quep)malloc(len);
	printf("I AM HERE 1");
}

linkq ADDD(linkq head,int x)
{
	Qnode *p;
	p=(quep)malloc(len);
	p=head.front->next;
	p->next=NULL;
	p->data=x;
	head.front=p;
	printf("I am here");
	return head;
}
void schu(linkq head)
{
	Qnode *p;
	for(p=head.front;p;p=p->next)
	{
		printf("shuchu:%d\n",p->data);
	}
	printf("I am here 3");
}

int main()
{
	linkq head;
	head=initqueue();
	linkq addd,aaa;int x=888;int y=999;
	addd=ADDD(head,x);
	aaa=ADDD(addd,y);
	schu(addd);
	return 0;
}
