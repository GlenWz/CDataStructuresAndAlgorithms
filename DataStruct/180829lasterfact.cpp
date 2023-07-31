#include <Stdio.h>
#include <Stdlib.h>

int main()
{
	int num=460897024;
	int fact=2;
	int lastfact=1;
	while(num>1)
	{
		if(num%fact==0)
		{
			lastfact=fact;
			num=num/fact;
			while(num%fact==0)
			{
				num=num/fact;
			}
		}
		fact=fact+1;
	}
	printf("%d\n",lastfact);
}
