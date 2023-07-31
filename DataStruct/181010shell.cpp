#include <stdio.h>
#include <Stdlib.h>
#define MAXSIZE 20
typedef struct d{
	int data[MAXSIZE];
	int left,right;
}sql;

sql *builds()
{
	sql *s=(sql *)malloc(sizeof(sql));
	s->left=0;
	s->right=13;
	for(int i=0;i<s->right;i++)
	{
		s->data[i]=i*i;
	}
	for(int i=s->right;i<MAXSIZE;i++)
	{
		s->data[i]=i+i;
	}
	return s;
}
void shell(sql *s)
{
	int tmp,j,i,a;
	for(i=5;i>0;i/=5)
	{
		for(j=i;j<MAXSIZE;j+=i)
		{
			tmp=s->data[j];
			for(a=j;s->data[a-i]>tmp&&a>0;a-=i)
			{
				s->data[a]=s->data[a-i];
			}
			s->data[a]=tmp;
		}
	}
}
void print(sql *s)
{
	for(int i=0;i<MAXSIZE;i++){
		printf("%d->",s->data[i]);
	}
}


int main()
{
	sql *s=builds();
	shell(s);
	print(s);
}
