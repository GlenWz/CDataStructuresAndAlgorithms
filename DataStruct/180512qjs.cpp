#include<stdio.h>
int main()
{
	int n=5;
	
 float a[n],x,sum;
 int i;
 printf("Please input the value of x=");
 scanf("%f",&x);
 for(i=n;i>=0;i--)
 {
  printf("Please input the value of a%d=",i);
  scanf("%f",&a[i]);
 }
 sum=a[n];
 for(i=n;i>=1;i--)
 {
  sum=sum*x+a[i-1];
 }
 printf("f(x)=%f\n",sum);
 return 0;
}
