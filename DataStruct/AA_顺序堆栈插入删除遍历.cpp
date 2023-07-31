#include <Stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct d{
	int data[MAX];
	int top;
}heap;

heap *buildh()
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->top=0;
	return h;
}
heap *insert(heap *h)
{
	heap *head=h;
	for(int i=0;i<10;i++)
	{
		h->data[i]=i*i;
		h->top=i;
	}
	return head;
}
heap *del(heap *head)
{
	heap *ret=head;
	head->data[head->top]=NULL;
	head->top--;
	return ret;
}
void Print(heap *head)
{
	for(int i=0;i<head->top;i++)
	{
		printf("%d->",head->data[i]);
	}
	printf("\n");
}
int main()
{
	heap *hp1=buildh();
	heap *hp2=insert(hp1);
	Print(hp2);	
	heap *hhp=del(hp2);
	Print(hhp);
}
