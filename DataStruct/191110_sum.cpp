#include <stdio.h>
#include <stdlib.h>

void Fuli(double &sum,int y)
{
	double sumbj=0;
	double bj[]={8000.0,100000.0,150000.0,200000.0,230000.0,250000.0,300000.0,350000.0};
	for(int i=0;i<y;i++)
	{
		printf("第%d年，输入本金，和额外的金额:\n",i+1);
	//	scanf("%lf",&bj);
		printf("the year's interest:%lf\n",1.08*(sum+bj[i])-(sum+bj[i]));
		sum=(sum+bj[i])*(1+0.12);
		sumbj+=bj[i];
		
	}
	printf("the sum is %lf\n",sum);	
	printf("\nthe interest is %lf\n",sum-sumbj);
}

int main()
{
	double sum;
	int y=8;
	Fuli(sum,y);

}








