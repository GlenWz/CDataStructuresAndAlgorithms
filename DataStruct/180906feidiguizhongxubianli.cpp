#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#define maxsize 10
//输入案例：1	2	3	0	0	4	0	0	5	6	0	0 	；
//不必建立一棵树，由中序遍历和前序遍历得到后序遍历 
int MID[maxsize]={};
int PRE[maxsize]={};
int POS[maxsize]={};

typedef struct {
	int data[maxsize];
	int top;
}stack;

stack *buildstack()
{
	stack *s=(stack *)malloc(sizeof(stack));
	s->top=-1;
	return s;
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
bool isempty(stack *s)
{
	if(s->top==0)
	{
		return 1;
	}else 
	{
		return 0;
	}
}

void push(stack *s,int tmp)
{
	if(isfull(s))
	{
		printf("the stack is full!");
	}
	s->top++;
	s->data[s->top]=tmp;
	
}
int pop(stack *s)
{
	if(isempty(s))
	{
		printf("the stack is empty!\n");
	}
	int ret;
	ret=s->data[s->top];
	s->top--;
	return ret;
}
void mid(int MID[maxsize],int PRE[maxsize])
{
	int tmp;
	int i=0,j=0,n=0;
	stack *s=buildstack();
	while(i<6)
	{
		printf("please input the tmp:\n");
		scanf("%d",&tmp);
		if(tmp>0&&tmp<10)
		{
			push(s,tmp);
			PRE[j]=tmp;
			++j;
		}
		if(tmp==0)
		{
			MID[i]=pop(s);
			i++;
		}
	}
}
void print(int MID[maxsize])
{
	for(int i=0;i<6;i++)
	{
		printf("%d->",MID[i]);
	}
	printf("\n");
}
int post(int prel,int midl,int posl,int n)
{
	if(n==0)
	{
		return NULL;
	}
	if(n==1)
	{
		POS[posl]=PRE[prel];
		return 0;
	}
	int i,L,R;
	int root;
	root=PRE[prel];
	POS[posl+n-1]=root;
	for(i=0;i<n;i++)
	{
		if(MID[midl+i]==root)
		{
			break;
		}
	}
//	printf("the L=%d",i);
	L=i;
	R=n-L-1;
	post(prel+1,midl,posl,L);
	post(prel+L+1,midl+L+1,posl+L,R);
}

int main()
{
	mid(MID,PRE);
	print(MID);
	print(PRE);
	post(0,0,0,6);
	print(POS);
	printf("%d",MID[3]);
}
