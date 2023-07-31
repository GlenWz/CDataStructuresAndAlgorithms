#include <Stdio.h>
#include <Stdlib.h>

void Achieve(char a[],char b[],int lena,int lenb,char ab[])
{
	int  i,j,k,s,tmp;
	for(i=0,k=0;i<lena;i++)
	{
		tmp=1;
		for(j=0;j<lenb;j++)
		{
			if(a[i]==b[j])
			{
				tmp=-1;
				break;
			}
		}
		for(s=i-1;s>=0;s--)
		{
			if(a[i]==a[s])
			{
				tmp=-1;
				break;
			}
		}
		if(tmp!=-1)
		{
			ab[k++]=a[i];
		}
	}
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
	char a[]="mstringAABBCCDD";
	char  b[]="stringD";
	int lena=sizeof(a)/sizeof(a[0])-1;
	int lenb=sizeof(b)/sizeof(b[0])-1;
	char ab[lena];
	Achieve(a,b,lena,lenb,ab);
	Print(ab);
 } 
