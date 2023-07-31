#include <Stdio.h>
#include <Stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct {
	struct node *front;
	struct node *rear;
}stack;
bool isempty(stack *s);

stack *initiative()
{
	stack *head=(stack *)malloc(sizeof(stack));
	head->front=head->rear=NULL;
	return head;
}

stack *build(stack *h)
{
	int x=111;
	node *s=(node *)malloc(sizeof(node));
	if(s!=NULL)
	{
		s->data=x;
		s->next=NULL;
		if(isempty(h))
		{
			h->front=s;
		}else 
		{
			h->rear->next=s;
		}
		h->rear=s;
	}
	return h;
}
stack *TEN(stack *h)
{
	int x=123;
	for(int i=0;i<10;i++)
	{
		node *n=(node *)malloc(sizeof(node));
		n->next=NULL;
		n->data=x-i*i;
		h->rear->next=n;
		h->rear=n;
	}
	return h;
}
int DEL(stack *s)
{
	int ret;
	node *f;
	if(isempty(s))
	{
		printf("the xxx is empty!");
		return NULL;
	}
	f=s->front;
	s->front=f->next;
	ret=f->data;
	free(f);
	return ret;
}
void traversal(stack *s)
{
	node *h=s->front;
	for(;h;h=h->next)
	{
		printf("%d\t",h->data);
	}
	printf("\n---------------------------------------\n");
}
bool isempty(stack *s)
{
	if(s->front==NULL&&s->rear==NULL)
	{
		return 1;
	}else 
	{
		return 0;
	}
}

int main()
{
	stack *s=initiative();
	stack *i=build(s);
	stack *ten=TEN(i);
	traversal(ten);
	int del=DEL(ten);
	traversal(ten);
	printf("DEL=%d\n",del);
	return 0;
}
