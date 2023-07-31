#include <Stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct d{
	int data[MAX];
	int top;
}stack;

stack *build()
{
	stack *n=(stack *)malloc(sizeof(stack));
	n->top=-1;
	return n;
}
void push(char c,stack *head)
{
	if(head->top==MAX-1)
	{
		printf("overflow!");
	}
	++head->top;
	int base='0';
	int s=c-base;
	printf("PUSH:%d\n",s);
	head->data[head->top]=s;
}
int pop(stack *head)
{
	printf("%d\n",head->top);
	if(head->top==-1)
	{
		printf("error!meiyoushule\n");
		return NULL;
	}
	int ret=head->data[head->top--];
	printf("pop:%d\n",ret);
	return ret;
}

int Cal(char *str,stack *head)
{
	
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='+')
		{	
			int num1=pop(head);
			int num2=pop(head);
			int sum=0;
			sum=num1+num2;
			push(sum,head);
		}else if(str[i]=='-')
		{
			int num1=pop(head);
			int num2=pop(head);
			int sum=0;
			sum=num2-num1;
			push(sum,head);
		}else if(str[i]=='*')
		{
			int num1=pop(head);
			int num2=pop(head);
			int sum=0;
			sum=num1*num2;
			push(sum,head);
		}else if(str[i]=='/')
		{
			int num1=pop(head);
			int num2=pop(head);
			if(num1==0)
			{
				printf("error!chushibuneng wei 0\n");
			}
			int sum=0;
			sum=num2/num1;
			push(sum,head);
		}else 
		{
			push(str[i],head);
		}
	}
	int ret=pop(head);
	return ret;
}

int main()
{
	stack *new1=build();	
	char str[15]="62/3-42*+";
	int res=Cal(str,new1);
	printf("%d",res);
	
}
