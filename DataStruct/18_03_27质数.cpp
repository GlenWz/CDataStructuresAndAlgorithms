#include <stdio.h>

int isP(int i,int prime[],int cnt);
int main()
{
	const int number=100;
	int prime[number]={2,};
	int cnt=1;
	int i=3; 
	while(cnt<number)
	{
		if(isP(i,prime,cnt))
		{
			prime[cnt++]=i;
		}
		i++;
	}
	for(i=0;i<number;i++)
	{
		printf("%d\t",prime[i]);
	}
	return 0;
 } 
 
 int isP(int x,int kp[],int nokp)
 {
 	int ret=1;
 	int i;
 	for(i=0;i<nokp;i++)
 	{
 		if(x%kp[i]==0)
 		{
 			ret=0;
 			break;
		 }
	 }
	 return ret;
 }
