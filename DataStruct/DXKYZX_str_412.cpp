#include <stdlib.h>
#include <stdio.h>

void Replace(char str[],char ab[],char zy[],int strlen,int lenab)
{
	int tmp,ia,is,iz;
	ia=0;
	tmp=0;
	int i;
	for(i=0;i<strlen;)
	{
		if(str[i]==ab[ia])
		{
			++i;
			++ia;
			if(ia==2)
			{
				
				for(int s=i-2,t=0;t<2;s++,t++)
				{
					str[s]=zy[t];
				}
			
				ia=0;
			}
			
		}else 
		{
			ia=0;
			i++;
		}
	}
}
void print(char str[],int lenstr)
{
	for(int i=0;i<lenstr;i++)
	{
		printf("%c",str[i]);
	}
	printf("\n");
}



int main()
{
	char str[]="CABABCABCABAB";
	
	char ab[]="AB";
	char zy[]="ZY";
	int lenstr=sizeof(str)/sizeof(str[0])-1;
	print(str,lenstr);
	printf("\n");
	int lenab=sizeof(ab)/sizeof(ab)-1;
	Replace(str,ab,zy,lenstr,lenab);
	print(str,lenstr);
}
