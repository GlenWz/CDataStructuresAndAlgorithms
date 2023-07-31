#include <Stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct d{
	char data[MAX];
	int length;
}str;

str *builda()
{
	str *head=(str *)malloc(sizeof(str));
	head->length=0;
	return head;
}
str *buildb()
{
	str *head=(str *)malloc(sizeof(str));
	head->length=0;
	char sttr[]="according to this study!";
	for(int i=0;sttr[i]!='\0';i++)
	{
		head->data[i]=sttr[i];
		++head->length;
	}
	return head;
}

int StrAssign(str *str1,char *sttr)
{
	if(str1->length==MAX)
	{
		printf("the space is full!\n");
		return -1;
	}
	for(int i=0;sttr[i]!='\0';i++)
	{
		str1->data[i]=sttr[i];
		++str1->length;
	}
	return 1;
}
int CompareString(str *str1,str *str2)
{
	for(int i=0;i<str1->length&&i<str2->length;i++)
	{
		if(str1->data[i]!=str2->data[i])
		{
			return str1->data[i]-str2->data[i];
		}
	}
	return str1->length-str2->length;
}
int SonString(str *str1,char *strS)
{
	int j=0,i,cout;
	for(i=0;i<str1->length;i++)
	{
		if(str1->data[i]-strS[j]==0)
		{
			++j;
			cout=i;
			if(strS[j]=='\0')
			{
				return cout;
			}
		}else 
		{
			j=0;
		}
	}
	return -1;
}

void Print(str *str1)
{
	for(int i=0;i<str1->length;i++)
	{
		printf("%c",str1->data[i]);
	}
	printf("\n");
}

int main()
{
	str *str1=builda();
	char sttr1[]="what the news report mean aboout ?";
	int num=StrAssign(str1,sttr1);
	Print(str1);
	int length=str1->length;
	str *str2=buildb();
	int CS=CompareString(str1,str2);	
	printf("the string length is %d\n",str1->length);
	printf("the compare result is %d\n",CS);
	char strS1[]="about";
	int ZC=SonString(str1,strS1);
	printf("the string %d",ZC);
	
}
