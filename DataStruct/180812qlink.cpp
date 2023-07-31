#include <Stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct d{
	struct node *front;
	struct node *rear;
}linkq;
bool isempty(linkq *head);

linkq* build()
{
	linkq *s=(linkq *)malloc(sizeof(linkq));
	s->front=s->rear=NULL;
	return s;
}

linkq *insert(linkq* h,int x)
{
	linkq *head=h;
	node *s=(node *)malloc(sizeof(node));
	if(s!=NULL)
	{
		s->data=x;
		s->next=NULL;
		if(isempty(head))
		{
			head->front=s;
			
		}else 
		{
			head->rear->next=s;
		}
		head->rear=s;
	}
	return head;
}

bool isempty(linkq *head)
{
	if(head->front==NULL&&head->front==NULL)
	{
		return 1;
	}else
	{
		return 0;
	}
}

linkq *DEL(linkq *h)
{
	node *s;
	if(isempty(h))
	{
		printf("error!");
		return 0;
	}else 
	{
		s=h->front;
		h->front=s->next;
		free(s);
	}
	return h;
}
void bianli(linkq *h)
{
	node *s;
	for(s=h->front;s;s=s->next)
	{
		printf("%d\t",s->data);
	}
}



int main()
{
	linkq *s=build();
	int x=111;
	linkq *in=insert(s,x);
	linkq *ins=insert(s,x+111);
	bianli(ins);
	linkq *del=DEL(ins);
	printf("\n------------------------end\n");
	bianli(del);
	
}
