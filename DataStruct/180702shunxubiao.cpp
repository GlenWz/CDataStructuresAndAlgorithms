#include <stdio.h>
#include <stdlib.h>

#define maxsize 10

typedef struct l{
	int data[maxsize];
	int length;
}sql;

sql *build()
{
	sql *p=(sql *)malloc(maxsize*sizeof(sql));
	int i=10;
	sql *head=p;
	for(int j=0;j<maxsize;j++,i++)
	{
		head->data[j]=i;
		head->length=j+1;
	}
	return head;
}

sql *Del()
{
	sql *head;
	head=build();
	for(int i=0;i<sizeof(head->data)/sizeof(head->data[0]);i++)
	{
		if(head->data[i]==12)
		{
			for(int j=i;j<sizeof(head->data)/sizeof(head->data[0]);j++)
			{
				head->data[j]=head->data[j+1];
			}
			head->length--;
		}
		
	}
	return head;
}
sql * INS()
{
	sql *head;
	head=Del();
	printf("lllll=%d",head->length);
	int p1=12;
	for(int i=0;i<sizeof(head->data)/sizeof(head->data[0]);i++)
	{
		if(head->data[i]>p1)
		{
			for(int j=head->length+1;j>i;j--)
			{
				head->data[j]=head->data[j-1];
			}
			head->data[i]=p1;
			break;
		}
	}
	return head;
}

int main()
{
	sql *head;
	head=build();
	for(int i=0;i<sizeof(head->data)/sizeof(head->data[0]);i++)
	{
		printf("%d\n",head->data[i]);
	}
	printf("***********len=%d\n",head->length);
	sql *del,*ins;
	del=Del();
	for(int i=0;i<del->length;i++)
	{
		printf("del=%d\n",del->data[i]);
	}
	printf("***********len=%d\n",del->length);
	ins=INS();
	for(int i=0;i<sizeof(ins->data)/sizeof(ins->data[0]);i++)
	{
		printf("int=%d\n",ins->data[i]);
	}
	printf("***********len=%d\n",ins->length);
	return 0;
	
}
