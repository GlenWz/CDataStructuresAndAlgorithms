#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef struct d{
	int data[maxsize];
	int len;
}sql;

sql *build()
{
	sql *s=(sql *)malloc(sizeof(sql));
	int x=50;
	for(int i=0;i<maxsize;i++,x--)
	{
		s->len=i;
		s->data[i]=x;
	}
	s->len++;
	return s;
}

sql *Del(sql *s,int pos)
{
	if(s->len==0)
	{
		printf("the xx is empty");
		return 0;
	}
	for(int i=0;i<s->len;i++)
	{
		if(i>=(pos-1))
		{
			s->data[i]=s->data[i+1];
		}
	}
	s->data[s->len-1]==NULL;           //这一步是重点***** 
	printf("%d****\n",s->len);
	s->len--;
	return s;
}
sql *insert(sql *s,int pos,int x)
{
	if(s->len==maxsize)
	{
		printf("the xxx is full");
		return 0;
	}
	
	for(int i=0;i<s->len;i++)
	{
		if(i>=pos-1)
		{
			s->len++;
			for(int j=s->len;j>i;j--)
			{
				s->data[j]=s->data[j-1];
			}
			s->data[pos-1]=x;
			break;	
		}
	}
	printf("%d\n",s->len);
	return s;
}

void bianli(sql *s)
{
	for(int i=0;i<s->len;i++)
	{
		printf("%d\t",s->data[i]);	
	}
	printf("\n--------------------------\n");
}

int main()
{
	sql *s=build();
	int pos =5;	int x=888;
	sql *del=Del(s,pos);
	bianli(del);
	sql *ins=insert(del,pos,x);
	bianli(ins);
}
