#include <Stdio.h>
#include <Stdlib.h>


int MAX(int a[],int &len,int &max)
{
	if(len==0)
	{
		return NULL;
	}else 
	{
		
		if(a[len]>=max)
		{
			max=a[len];
		}
		len--;
		MAX(a,len,max);
	}
}

int SUM(int a[],int &len,int &sum)
{
	if(len<0)
	{
		return NULL;
	}else 
	{
		sum+=a[len--];
		SUM(a,len,sum);
	}
}
float AVGDG(int a[],int &len,float &sum,int &n)
{
	if(len==0)
	{
		sum+=a[len];
		n++;
		return sum/n;
	}else 
	{
		sum+=a[len--];
		n++;
		AVGDG(a,len,sum,n);
	}
}



int main()
{
	int a[20];
	for(int i=0;i<20;i++)
	{
		a[i]=i+9;
	}
	int len=19;
	int max=a[0];
	MAX(a,len,max);	
	printf("the MAX IS :%d\n",max);
	int sum=0;
	len=19;
	SUM(a,len,sum);
	printf("the sum is :%d\n",sum);
	float AVG=0.0;
	len=19;
	float Sum=0.0;
	int n=0;
	AVG=AVGDG(a,len,Sum,n);
	printf("the AVG is :%lf\n",AVG);
}
