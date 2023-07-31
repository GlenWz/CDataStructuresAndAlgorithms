#include <stdio.h>
#include <stdlib.h>
#define maxsize 20

typedef struct d{
	int data[maxsize];
	int length;
}sqli;

sqli *build()
{
	sqli *head=(sqli *)malloc(sizeof(sqli));
	int d=10;
	for(int i=0;i<maxsize-1;i++,d++)
	{
		head->data[i]=d;
		head->length=i;
	}
}

int erfen(sqli *head,int x)
{
	int l;int r; int mid; int ret=0;
	int i=0;
	l=0;r=head->length;
	while(r>l)
	{
		mid=(l+r)/2;
		if(head->data[mid]>x)
		{
			r=mid-1;
		}
		else if(head->data[mid]==x)
		{
			ret=1;
			break;
		}else
		{
			l=mid+1;
		}
		
	}
	return ret;
}


int main()
{
	sqli *head;
	head=build();
	int x=26; int Erfen;
	Erfen=erfen(head,x);
	printf("%d\n",Erfen);
	
}
