#include <Stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
typedef struct n{
	struct node *top;
}heap;

heap *build()
{
	heap *head=(heap *)malloc(sizeof(heap));
	head->top=NULL;
	return head;
}
heap *insert(heap *head)
{
	heap *ret=head;
	for(int i=0;i<8;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*i;
		s->next=head->top;
		head->top=s;
		
	}
	return ret;
}
heap *Del(heap *head)
{
	heap *h=head;
	if(head->top==NULL)
	{
		printf("error!");
		return 0;
	}else 
	{
		node *s=head->top;
		head->top=s->next;
		free(s);	
	}
	return h;
}
void Print(heap *head)
{
	node *h=head->top;
	for(h;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}
int main()
{
	heap *h=build();
	heap *hh=insert(h);
	Print(hh);
	heap *hhh=Del(hh);
	Print(hhh);
}
