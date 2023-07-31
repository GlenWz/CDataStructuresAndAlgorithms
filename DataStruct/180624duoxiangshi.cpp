#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct playnode{
	int coef;int expon;
	struct playnode *next;
}link;

link *build()
{
	int i=0;int j=0;
	int a[3]={3,2,1,}; int b[2]={-4,1};
	int x[3]={2,1,0,}; int y[2]={2,1,};
	link *head,*q,*q1,*p,*s;
	link *l1=(link *)malloc(sizeof(link));
	link *l2=(link *)malloc(sizeof(link));
	link *l3=(link *)malloc(sizeof(link));
	link *p1=(link *)malloc(sizeof(link));
	link *p2=(link *)malloc(sizeof(link));
	
	link *j1=(link *)malloc(sizeof(link));
	link *j2=(link *)malloc(sizeof(link));
	link *j3=(link *)malloc(sizeof(link));
	
	q=l1; l1->next=l2;l2->next=l3;l3->next=NULL;
	p=p1; p1->next=p2;p2->next=NULL;
	s=j1; j1->next=j2;j2->next=j3;j3->next=NULL;
	
	for(q;q;q=q->next,i++)
	{
		q->coef=a[i];
		q->expon=x[i];
	//	printf("q->c %d\t",q->coef);
	//	printf("%d\t",q->expon);
	}
	
	for(p;p;p=p->next,j++)
	{
		p->coef=b[j];
		p->expon=y[j];
	}
	for(q,p;s;q=q->next,p=p->next,s=s->next)
	{
		if((q->expon)>(p->expon))
		{
			s->coef=q->coef;
			printf("%d\t",s->coef);
			s->expon=p->expon;
		}
		else if((q->expon)==(p->expon))
		{
			j1->coef=q->coef+p->coef;
			s->expon=p->expon;
			printf("%d\t",s->coef);
		}
		else{
			s->coef=p->coef;
			s->expon=q->expon;
		}
	}
	return s;
}

int main()
{
	link *head,*q,*p;
	head=build();
	for(q=head;q;q=q->next)
	{
		printf(" %dX^%d+",q->coef,q->expon);
	}
	
	
	return 0;
}



