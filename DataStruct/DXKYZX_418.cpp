#include <Stdio.h>
#include <stdlib.h>

int ChaNum(char str[],int strlen)    //ʱ�临�Ӷ�̫���ˣ��������� 
{									//����ascii��ֻ��127���ַ����Ժ��Բ��� 
	int ret=1;
	int i,j,k,tmp;
	char com[strlen];
	int comlen=1;
	for(j=0;j<strlen-1;j++)
	{
		tmp=1;
		com[j]=str[j];
		++comlen;
		for(k=0;k<comlen;k++)
		{
			if(str[j+1]==com[k])
			{
				tmp=0;
			}
		}
		if(tmp!=0)
		{
			ret++;
		}
	}
	return ret;
}



int main()
{
	char str[]="45djk435/10./*+qlkjk1!@#$%^**()_+:',j'vzawvSSDKJLJGSERWNP";
	int strlen=sizeof(str)/sizeof(str[0])-1;
	printf("%d\n",strlen);
	int num=ChaNum(str,strlen);
	printf("the num is %d\n",num);
}
