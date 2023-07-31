#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;
int DEL(link *head,int x);

link *build()
{
	link *head,*rear;
	head=(link *)malloc(sizeof(link));
	rear=(link *)malloc(sizeof(link));
	head->next=rear;rear->next=head;
	head->data=NULL;rear->data=NULL;
	int num;
	int a[]={4,6,7,8,9,3,1,5,6,7,10,11,15,18};
	printf("please input the num");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		link *s=(link*)malloc(sizeof(link));
		s->next=head;
		s->data=a[i];
		rear->next=s;
		rear=s;
	}
	rear->next=NULL;
	return head->next;
}
int DEL(link *head,int x)
{
	link *p,*q,*h;
	int ret=0;
	for(h=head,q=NULL;h;q=h,h=h->next)
	{
		if(h->data==x)
		{
			if(q)
			{
				q->next=h->next;
				ret=1;
				free(h);
				break;
			}else
			{
				head=h->next;
			}
		}
	}
	return ret;
}

void bianli(link *head)
{
	link *h=head;
	for(h;h;h=h->next)
	{
		printf("%d\n",h->data);
	}
	printf("-------------end\n");
}




int main()
{
	link *head=build();
	bianli(head->next);
	int x=11; int ret;
	ret=DEL(head,x);
	printf("ret=%d\n",ret);
	bianli(head->next);
}
