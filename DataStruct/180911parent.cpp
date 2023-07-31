#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#define maxsize 10
typedef struct {
	int data[maxsize];
	int present[maxsize];
}settype;



settype *builds()
{
	settype *s=(settype *)malloc(sizeof(settype));
	for(int i=0;i<maxsize;i++)
	{
		s->data[i]=i*i;
	}
	for(int j=0;j<maxsize;j++)
	{
		if(j>=1&&j<3)
		{
			s->present[j]=0;
		}else if(j>=6&&j<=8)
		{
			s->present[j]=9;
		}else if(j>=3&&j<6)
		{
			s->present[j]=2;
		}else
		{
			s->present[j]=-1;
		}
	}
	return s;
}
int find(settype *s,int x)
{
	int i;
	for(i=0;i<maxsize&&s->data[i]!=x;i++)
	{
	}
//	printf("%d\n",i);
	if(i>=maxsize)
	{
		printf("404 NOT Find!\n");
		return -1;
	}
	for(;s->present[i]>=0;i=s->present[i])
	{
	}
	return i;
}
void print(settype *s)
{
	printf("\nThe SET:\n");
	for(int i=0;i<maxsize;i++)
	{
		printf("S->DATA:%d\t",s->data[i]);
		printf("S->PART:%d\n",s->present[i]);
	}
}
void Union(settype *s,int x,int y)
{
	int root1,root2;
	root1=find(s,x);
	root2=find(s,y);
	if(root1!=root2)
	{
		s->present[root1]=root2;
	}
}

int main()
{
	int x=81;
	settype *s=builds();
	int parent=find(s,64);
	printf("\nthe paren is %d:\n",parent);
	print(s);
	Union(s,81,4);
	int UN=find(s,64);
	printf("\n-----------------------------------endge\n");
	print(s);
	printf("%d\n",UN);
}

