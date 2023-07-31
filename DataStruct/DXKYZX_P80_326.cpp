#include <Stdio.h>
#include <Stdlib.h>

int Ack(int m,int n,int &seq)
{
	int tmp;
	if(m==0)
	{
		seq++;
		printf("\nM==0 m:%d\tn:%d\tseq:%d\n",m,n,seq);
		return n+1;
	}else 
	{
		if(n==0)
		{
			seq++;
			printf("\n N==0 m:%d\tn:%d\tseq:%d\n",m,n,seq);
			return (Ack(m-1,1,seq));
		}else if(n!=0)
		{
			seq++;
  			printf("\n N!=01 m:%d\tn:%d\tseq:%d\n",m,n,seq);
			tmp=Ack(m,n-1,seq);
			seq++;
			printf("\n N!=02m:%d\tn:%d\tseq:%d\n",m,n,seq);
			return (Ack(m-1,tmp,seq));
		}
		
	}	
}


int main()
{
	int m,n,sum=0,seq=0;
	m=4;
	n=2;
	sum=Ack(m,n,seq);
	printf("%d\n",sum);
}



