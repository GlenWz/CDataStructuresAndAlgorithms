#include <stdio.h>

int main()
{
	int i,j,k,z;

	for(i=100;i<1000;i++)
	{
		j=i%10;
		k=i/10%10; 
		z=i/100%10;
		if(i==(j*j*j+k*k*k+z*z*z))
		printf("%d\n",i);
	}
	return 0;
	
}
