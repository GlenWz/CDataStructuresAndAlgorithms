#include <Stdio.h>
//123 
//246
//369

int main()
{
	int i,j,n;
	for(i=1,n=1;i<=3;i++,n++)
	{
		printf("%d\t",i);
		if(n%3==0)
		{
			printf("\n");
		}
		for(i=2;i<6;i+=2)
		{
			printf("%d\t",i);
		}
	}
}

