#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 10

typedef struct d{
	int data[maxsize];
	int length;
}sql;

sql *build()
{
	sql *s=(sql *)malloc(sizeof(sql));
	s->length=maxsize;
	for(int i=0;i<5;i++)
	{
		s->data[i]=i*8;
	}
	for(int j=5;j<s->length;j++)
	{
		s->data[j]=(j+15);
	}
	return s;
}

sql *swap(sql *s)
{
	int tmp;
	int i,j,m=5;
	for(i=0,m;i<=m&&m<maxsize;i++)
	{
		if(s->data[i]>s->data[m])
		{
			tmp=s->data[i];
			printf("si==%d\t",s->data[i]);
			s->data[i]=s->data[m];
			printf("i=%d  m=%d si=%d  \n",i,m,s->data[i]);
			s->data[m]=tmp;
			m++;
		}
		if(m==maxsize)
		{
			for(j=i+1;j<maxsize;j++,i++)
			{
				if(s->data[i]>s->data[j])
				{
					tmp=s->data[i];
					s->data[i]=s->data[j];
					s->data[j]=tmp;
				}
			}
		}
	}
	
	return s;
}
void print(sql *s)
{
	for(int i=0;i<maxsize;i++)
	{
		printf("%d\t",s->data[i]);
	}
	printf("\n--------------------------------------------\n");
}

int main()
{
	sql *s=build();	
	print(s);
	swap(s);
	print(s);
}
