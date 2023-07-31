#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 10

typedef struct d{
	int data[maxsize];
	int len;
}sql;

sql *build()
{
	sql *s=(sql *)malloc(sizeof(sql));
	int x=10;
	for(int i=0;i<maxsize;i++,x+=10)
	{
		s->data[i]=x;
		s->len=i;
	}
	s->len++;
	return s;
}
sql *DEL(sql *s,int pos)
{
	if(s->len==0)
	{
		printf("the xxx is empty");
		return NULL;
	}
	for(int i=0;i<s->len;i++)
	{
		if(i==(pos-1))
		{
			s->data[i]=s->data[i+1];
		}
	}
	s->data[s->len-1]==NULL;
	s->len--;
	return s;
}
sql *insert(sql *s,int x)
{
	for(int i=0;i<s->len;i++)
	{
		if(s->data[i]>=x)
		{
			s->len++;
			for(int j=s->len;j>i;j--)
			{
				s->data[j]=s->data[j-1];
			}
			s->data[i]=x;
			break;
		}
	}
	return s;
}

void bianli(sql *s)
{
	for(int i=0;i<s->len;i++)
	{
		printf("%d\t",s->data[i]);
	}
	printf("\n-----------------------------------\n");
}

int main()
{
	sql *s=build();
	int x=55;
	int pos=5;
	sql *del=DEL(s,pos);
	sql *de=DEL(del,pos);
	bianli(de);
	sql *ins=insert(de,x);
	bianli(ins);
	
}
