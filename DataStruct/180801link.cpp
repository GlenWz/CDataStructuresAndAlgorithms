#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *build()
{
	int num;
	printf("please input");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=num;
		s->next=build();
		//return s;
	}
}

link *chong(link *head)
{
	link *h,*q,*p;
	for(h=head;h;h=h->next)
	{
		for(q=h->next,p=NULL;q;p=q,q=q->next)
		{
			if(q->data==h->data)
			{
				if(p)
				{
					p->next=q->next;
					free(q);
					break;
				}else
				{
					h->next=p->next;
				}
			}
		}
		
	}
	return q;
}




void print(link *head)
{
	link *h;
	for(h=head;h;h=h->next)
	{
		printf("%d\n",h->data);
	}
	printf("------------------------end\n");
}


int main()
{
	link *head=build();
	print(head);
	link *s=chong(head);
	print(s);
}
