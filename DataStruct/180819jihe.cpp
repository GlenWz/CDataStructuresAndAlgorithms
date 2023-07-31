#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 9

typedef struct d{
	int data[maxsize];
	int parentpos[maxsize];
}sset;

sset *build()
{
	sset *s=(sset *)malloc(sizeof(sset));
	for(int i=0;i<maxsize;i++)
	{
		s->data[i]=i+5;
		if(i==8||i==9)
		{
			s->parentpos[i]=-1;
		}else if(i<5)
		{
			s->parentpos[i]=8;
		}else 
		{
			s->parentpos[i]=9;
		}
	}
	return s;
}
/*
void print(sset *s)
{
	for(int i=0;i<)
}*/
int findx(sset *s,int x)
{
	int i;
	for(i=0;i<maxsize&&s->data[i]!=x;i++)
	{	
	}
	if(i>=maxsize)
	{
		return -1;
	}
	for(s->parentpos[s->parentpos[i]]>=0;s->data[])
	{
		return s->parentpos[i];
	}
	
}
void Union(sset *s,int x,int y)
{
	int root1=findx(s,x);
	int root2=findx(s,y);
	if(root1==root2)
	{
		printf("the root is same");
	}else 
	{
		for(int i=0;i<maxsize;i++)
		{
			if(s->data[i]==root1)
			{
				s->parentpos[i]=root2;
			}
		}
	}
}

void jiancha(sset *s)
{
	for(int i=0;i<maxsize;i++)
	{
		printf("child=%d\t parent=%d\n",s->data[i],s->parentpos[i]);
		
	}
}

int main()
{
	sset *st=build();
	int x=6; int y=13;
	int j=findx(st,x);
	printf("%d\n",j);
	Union(st,x,y);              //liang ge ji he de bing cao zuo 
	jiancha(st);
	return 0;
}
