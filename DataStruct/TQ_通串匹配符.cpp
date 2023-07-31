#include <Stdio.h>
#include <Stdlib.h>


int FUCK(char str[],int strlen,char pat[],int patlen)
{
	int i,j,k=1;
	for(i=1,j=1;i<strlen;)
	{
		if(str[i]==pat[j])
		{
			j++;
			k++;
			i++;
			if(j=patlen-1)
			{
				return i-j;
			}
			
		}else 
		{
			j=1;
			i++;
		}
	}
	return -1;
}




int main()
{
	char str[]="BCA JSK DSKL I JSK";
	char pat[]="?SK";
	int strlen=sizeof(str)/sizeof(str[0])-1;
	int patlen=sizeof(pat)/sizeof(pat[0])-1;
	int pos=FUCK(str,strlen,pat,patlen);
	if(pos==-1)
	{
		printf("not find£¡\n");
	}else 
	{
		printf("the pos  is :%d\n",pos);
	}
	
}
















