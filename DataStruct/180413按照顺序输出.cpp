#include <stdio.h>
//有三个数按照大小顺序输出 
int main()
{
	int max;
	int mid;
	int min;
	int a[2]={};
	for(int i=0;i<3;i++)
	{
		scanf("%d",&a[i]);
	 } 
	 for(int i=0;i<3;i++)
	 {
	 	if(a[i]>max)
	 	{
	 		max=a[i];
		 }
		 if(a[i]<min)
		 {
		 	min=a[i];
		 }
	    if(a[i]!=max&&a[i]!=min)
		{
			mid=a[i];
			}	
		
	 }
	 printf("%d\t %d\t %d\t",max,mid,min);
	 return 0;
	 
 } 
