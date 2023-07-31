#include <stdio.h>
#include <stdlib.h>
#define maxsize 50


typedef struct d{
	int data;
	struct d *left;
	struct d* right;
}tree;

typedef struct {
	int data[maxsize];
	int length;
}queue;

tree *build()
{
	int n;
	printf("plese input the value !");
	scanf("%d",&n);
	if(n==0)
	{
		return NULL;
	}
	else
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=n;
		s->left=build();
		s->right=build();
		return s;
	}
}
tree *pop(queue *s,int in)
{
	tree *h;
	h->data=s->data[in];
	return h;
}

void push(queue *s,tree *T,int in)
{
	s->data[in]=T->data;
	s->length++;
}
void MID(tree *head);;;;;;;;;;;;.6
{
	tree *T=head;
	int in=0;
	queue *s=(queue *)malloc(sizeof(queue));
	while(T||(s->length<maxsize-1))
	{
	
		while(T)
		{
			push(s,T,in);
			in++;
		}
		if(in!=-1)
		{
			T=pop(s,in);
			printf("%d\n",T->data);
			in--;
			T=T->right;
		}
	}
}

int main()
{
	tree *head;
	head=build();	
	MID(head);
}
