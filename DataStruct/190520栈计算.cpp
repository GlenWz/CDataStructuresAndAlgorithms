#include <Stdio.h>
#include <Stdlib.h>
#define MAX 100

typedef struct d{
	int data[MAX];
	int top;
}stack;

stack *builds()
{
	stack *s=(stack *)malloc(sizeof(stack));
	s->top=-1;
	return s;
}
void push(int j,stack *s)    //入栈 
{
	if(s->top==MAX-1)
	{
		printf("overflow!");
	}
	s->data[++s->top]=j;
	printf("PUSH:%d\n",s->data[s->top]);
}
int pop(stack *s)      //出栈 
{
	if(s->top==-1)
	{
		printf("error,NO NUMBER!");
	}
	return s->data[s->top--];
}

void Cal(char *str,stack *h)    //计算 
{
	for(int i=0;str[i]!='#';i++)
	{
		int a1,a2,sum;
		if(str[i]>='0'&&str[i]<='9')       //数字进栈 
		{
			int j=str[i]-'0';                 
			push(str[i],h);
		}else 
		{
			switch(str[i])
			{
				case '+':
					a1=pop(h);
					a2=pop(h);
					sum=a1+a2;
					push(sum,h);
					break;
				case '-':
					a1=pop(h);
					a2=pop(h);
					sum=a2-a1;
					push(sum,h);
					break;
				case '*':
					a1=pop(h);
					a2=pop(h);
					sum=a1*a2;
					push(sum,h);
					break;
				case '/':
					a1=pop(h);
					a2=pop(h);
					sum=a2/a1;
					push(sum,h);
					break;
				default:
					printf("DFerror!");
					break;
			}
		}
	}
}

int main()
{
	stack *s=builds();
	char str[15]="62/3-42*+#";   //后缀表达式 
	Cal(str,s);
	int sum=pop(s);
	printf("the result is :%d\n",sum);
	
}

