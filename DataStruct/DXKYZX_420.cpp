#include <stdio.h>
#include <stdlib.h>

int Del(char str[],char s[],int strlen,int slen)
{
	int ret=0;
	int i,j=0,k;
	for(i=0;i<strlen;)
	{
		if(str[i]==s[j])
		{
			j++;
			i++;
			if(j==slen)
			{
				for(k=i-j;k+j<strlen;k++)
				{
					str[k]=str[k+j];
				}
				for(k;k<strlen;k++)
				{
					if(str[k]!='\0')
					{
						str[k]='\0';
					}
				}
				i=i-j;    //这里必须加上这句，删除了之后数据往前移动了 
				j=0;	   
				ret++;
			}
		}else 
		{
			i++;
			j=0;
		}
	}
	return ret;
}

void Print(char ab[])
{
	for(int i=0;ab[i]!='\0';i++)
	{
		printf("%c",ab[i]);
	}
	printf("\n");
}





int main()
{
	char str[]="ststringstringstring";
	char s[]="st";
	int strlen=sizeof(str)/sizeof(str[0])-1;
	int slen=sizeof(s)/sizeof(s[0])-1;
	int num=Del(str,s,strlen,slen);
	Print(str);
	printf("删除了%d次\n",num);
}
