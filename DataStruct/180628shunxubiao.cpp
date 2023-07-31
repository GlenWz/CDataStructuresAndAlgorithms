#include <stdio.h>
#define maxsize 100
typedef struct x{
	int data[maxsize];
	int length;
}sqlist;

sqlist build()
{
	sqlist head,last;
	head->data=1;
	for(head->length==1;head->data<100;head->data++)
	{
		head->length++;
	}
	return head;
}



int main()
{
	sqlist p1;
	p1=build();
	for(p1->length==1;p1->data<100;p1->data++)
	{
		p1->length++;
		printf("%d\n",p1->data);
		if(p1->data==52)
		{
			printf("zhaodale");
		}
	}
	return 0;
	
}
