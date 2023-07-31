#include <Stdio.h>
#include <Stdlib.h>
#define max 20

typedef struct d{
	int x,y;
	int data;
}mat;

typedef struct {
	mat data[max];
	int n;
}woyebuzhidaozhejiaosha;

woyebuzhidaozhejiaosha *buildw(int a[][5],int n)
{
	woyebuzhidaozhejiaosha *s=(woyebuzhidaozhejiaosha *)malloc(sizeof(woyebuzhidaozhejiaosha));
	int renhaishiyaoyoudianmengxiangde=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				s->data[renhaishiyaoyoudianmengxiangde].data=a[i][j];
				s->data[renhaishiyaoyoudianmengxiangde].x=i;
				s->data[renhaishiyaoyoudianmengxiangde].y=j;
				renhaishiyaoyoudianmengxiangde++;
			}
		}
	}
	s->n=renhaishiyaoyoudianmengxiangde;
	return s;
}
int mamajiaowochazhaoyixiazhegeshuzaibuzailimian(woyebuzhidaozhejiaosha *s,int v,int &x,int &y)
{
	int ret=-1;
	
	for(int i=0;i<s->n;i++)
	{
		if(v==s->data[i].data)
		{
			ret=1;
			x=s->data[i].x;
			y=s->data[i].y;
			break;
		}
	}
	return ret;
}

void dayinchulaikankan(woyebuzhidaozhejiaosha *s)
{
	for(int i=0;i<s->n;i++)
	{
		printf("%d->",s->data[i].data);
	}
	printf("\n");
}

int main()
{
	int n=5;
	int a[5][5];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j-i||j==i-j||i==j)
			{
				a[i][j]=i+j;
				printf("%d\t",a[i][j]);
			}else
			{
				a[i][j]=0;
				printf("%d\t",a[i][j]);
			 } 
		}
			printf("\n");
	}
	
	woyebuzhidaozhejiaosha *s=buildw(a,n);
	dayinchulaikankan(s);
	int v=6;
	int x=1,y=2;
	int x1=-1,y1=-1;
	int ret=mamajiaowochazhaoyixiazhegeshuzaibuzailimian(s,v,x1,y1);
	if(ret!=-1)
	{
		printf("the position is %d %d",x1,y1);
	}
	
}
