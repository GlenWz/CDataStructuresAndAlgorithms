#include <stdio.h>
#include <stdlib.h>
#define maxsize 15
typedef struct d{
	char data[maxsize];
	int top;
}stack;
void push(stack *s,char a);
void pop(stack *s);
void pushc(stack *h);

stack *initiative()
{
	
	stack *s=(stack *)malloc(sizeof(stack));
	s->top=-1;
	return s;
}
void pushc(stack *h)
{
	stack *s=h;
	char exp[maxsize]="a*((b+c)-d)";
	for(int i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(')
		{
			push(s,'(');
		}
		if(exp[i]==')')
		{
			if(s->top==-1)
			{
				printf("bu pi pei!");
				system("PAUSE")	;	
			}else 
			{
				pop(s);
				printf("%c",exp[i]);
			}
		}
	}
}
void push(stack *s,char a)
{
	s->top++;
	s->data[s->top]=a;
	printf("%c",s->data[s->top]);
}
void pop(stack *s)
{
	s->data[s->top]=NULL;
	s->top--;
}


int main()
{
	stack *s=initiative();
	pushc(s);
	pop(s);
	return 0;
}
