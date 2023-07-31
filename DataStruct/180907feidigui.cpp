#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxsize 10
int pre[maxsize];
int mid[maxsize];
int pos[maxsize];

typedef struct snode{
	int data[maxsize];
	int top;
}stack;

bool isempty(stack *s)
{
	if(s->top==-1)
	{
		return 1;
	}else 
	{
		return 0;
	}
}
bool isfull(stack *s)
{
	if(s->top==maxsize)
	{
		return 1;
	}else 
	{
		return 0;
	}
}

stack *initiative()
{
	stack *s=(stack *)malloc(sizeof(stack));
	s->top=-1;
	return s;
}

void push(stack *s,int tmp)
{
	if(isfull(s))
	{
		printf("the stack is full!");
	}
	++s->top;
	s->data[s->top]=tmp;
}
int pop(stack *s)
{
	if(isempty(s))
	{
		printf("the stack is empty!");
		return NULL;
	}
	return s->data[(s->top)--];
}

void MID()
{
	int tmp;
	int i=0,j=0,n=0;
	stack *s=initiative();
	while(i<6)
	{
		printf("please input the tmp:\n");
		scanf("%d",&tmp);
		if(tmp!=0)
		{
			push(s,tmp);
			pre[j]=tmp;
			j++;
		}
		if(tmp==0)
		{
			mid[i]=pop(s);
			i++;
		}
	}
}
int POS(int prel,int midl,int posl,int n)
{
	if(n==0)
	{
		return NULL;
	}
	if(n==1)
	{
		pos[posl]=pre[prel];
		return 0;
	}
	int i,l,r;
	int root;
	root=pre[prel];
	pos[posl+n-1]=root;
	for(i=0;i<n;i++)
	{
		if(mid[midl+i]==root)
		{
			break;
		}
	}
	l=i;
	r=n-l-1;
	POS(prel+1,midl,posl,l);
	POS(prel+l+1,midl+l+1,posl+l,r);
}

void print(int a[])
{
	for(int i=0;a[i]!='\0';i++)
	{
		printf("%d->",a[i]);
	}
	printf("\n");
}
int main()
{
	MID();
	print(pre);
	print(mid);
	POS(0,0,0,6);
	print(pos);
}
