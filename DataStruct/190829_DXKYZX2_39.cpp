#include <Stdio.h>
#include <stdlib.h>

typedef struct {
	int coef;
	int exp;
}Ploytem;

typedef struct {
	Ploytem *data;
	int last;
}SqPloy;

SqPloy *Build()
{
	SqPloy *s=(SqPloy *)malloc(sizeof(SqPloy));
	s->last=4;
	for(int i=0;i<s->last;i++)
	{
		printf("please input the %d S_coef:\n",i);
		scanf("%d",&s->data[i].coef);
		printf("please input the %d S_exp:\n",i);
		scanf("%d",&s->data[i].exp);
	}
	return s;
}
int TheResult(SqPloy *s,int num)
{
	int count=0;
	int ret=0;
	int tmp=0;
	for(int i=0;i<s->last;i++)
	{
		tmp=s->data[i].coef*1;
		for(int j=s->data[i].exp;j>0;j--)
		{
			tmp=tmp*num;			
		}
		ret+=tmp;
	}
	return ret;
}
SqPloy *Buildb()
{
	SqPloy *b=(SqPloy *)malloc(sizeof(SqPloy));
	b->last=4;
	for(int i=0;i<b->last;i++)
	{
		printf("Please input the %d coef:\n",i);
		scanf("%d",&b->data[i].coef);
		printf("Please input the %d exp:\n",i);
		scanf("%d",&b->data[i].exp);
	}
	return b;
}
SqPloy *Subtraction(SqPloy *s,SqPloy *b)
{
	SqPloy *sb=(SqPloy *)malloc(sizeof(SqPloy));
	int count=0,i;
	for(i=0;i<s->last||i<b->last;i++)
	{
		if(s->data[i].exp==b->data[i].exp)
		{
			sb->data[i].coef=s->data[i].coef-b->data[i].coef;
			s->data[i].exp=s->data[i].exp;
			count++;
		}else if(i>s->last&&i<b->last)
		{
			sb->data[i].coef=-1*b->data[i].coef;
			sb->data[i].exp=b->data[i].exp;
		}else if(i<s->last&&i>b->last)
		{
			sb->data[i].coef=s->data[i].coef;
			sb->data[i].exp=s->data[i].exp;
		}
	}
	return sb;
}



int main()
{
	SqPloy *s=Build();
	int result=TheResult(s,2);
	printf("\nThe result:%d\n",result);
	SqPloy *b=Buildb();
	SqPloy*sb=Subtraction(s,b);
	
	int RESB=TheResult(sb,2);
}






