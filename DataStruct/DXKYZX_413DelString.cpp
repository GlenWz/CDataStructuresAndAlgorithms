#include <stdio.h>
#include <Stdlib.h>
#define max 100

void Delete(char str[],int lenstr,char zoc[],int lenzi)
{
	int i,j,k;
	j=0;
	for(i=0;i<lenstr;)
	{
		if(str[i]==zoc[j])
		{
			j++;
			i++;
			if(j==lenzi-1)
			{
				
				
				
				
					for(k=i-j;k<lenstr-1;k++)
					{
						
							str[k]=str[k+lenzi];
							printf("%d\t%c\t%c\n",k,str[k],str[k+lenzi]);
						
					}
				
			}
		}else 
		{
			j=0;
			i++;
		}
	}
	
}
void Print(char str[])
{
	for(int i=0;str[i]!='\0';i++)
	{
		printf("%c",str[i]);
	}
	printf("\n");
}




int main()
{
	
	char str[]="abdBCAbddDBDDNDSABCAsdkj";
	int lenstr=sizeof(sizeof(str))/sizeof(str[0])-1;
	Print(str);
	char zic[]="BCA";
	int lenzi=sizeof(zic)/sizeof(zic[0])-1;
	Delete(str,lenstr,zic,lenzi);
	Print(str);
}
