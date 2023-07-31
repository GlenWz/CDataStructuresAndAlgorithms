#include <stdio.h>
#include <Stdlib.h>
#define maxsize 5

typedef struct d{
	int data[10];
	int length;
}sql;

sql *build(int x)
{
	sql *s=(sql *)malloc(sizeof(sql));
	s->length=maxsize;
	for(int i=0;i<maxsize;i++)
	{
		s->data[i]=i*x+1;
	}
	return s;
}

void output(sql *h)
{
	for(int i=0;i<h->length;i++)
	{
		printf("%d\t",h->data[i]);
	}
	printf("\n--------------------------------------------\n");
}
sql *mergesql(sql *s11,sql *s22)
{
	sql *s1=s11,*s2=s22;
	sql *m=(sql *)malloc(sizeof(sql));
	m->length=10;
	int j=0,l=0,i=0;
	for(i;s1->data[l]!=0&&s2->data[j]!=0;i++)
	{
		if(s1->data[l]>s2->data[j])
		{
			m->data[i]=s2->data[j];
			printf("S2:%d\t",s2->data[j]);
			j++;
		}else
		{
			m->data[i]=s1->data[l];
			printf("S1:%d\t",s1->data[l]);
			l++;
		}
	}
	if(s1->data[l]==0)
	{
		for(i;s2->data[j]!=0;i++,j++)
		{
			m->data[i]=s2->data[j];
		}
	}
	if(s2->data[j]==0)
	{
		for(i;s1->data[l];i++,l++)
		{
			m->data[i]=s1->data[l];
		}
	}
	printf("\n----\n");
	return m;
}



int main()
{
	int x=5;int y=2;
	sql *s1=build(x);
	sql *s2=build(y);
	output(s1);
	sql *sss=mergesql(s1,s2);
	output(sss);
}
