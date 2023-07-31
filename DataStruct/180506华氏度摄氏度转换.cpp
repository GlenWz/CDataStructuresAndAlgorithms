#include <stdio.h>
//摄氏度转华氏度 
int main()
{
	double f,c;
	printf("请输入华氏度：");
	scanf("%lf",&f); 
	printf("%lf\n",f);
	c=(5.0/9)*(f-32.0);
	printf("%lf",c);
	return 0; 
}
