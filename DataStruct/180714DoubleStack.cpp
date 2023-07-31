#include <stdio.h>
#include <stdlib.h>
#define maxsize 20

typedef struct d{
	int data[maxsize];
	int top1;
	int top2;
}dst;

dst *build()
{
	dst *p=(dst *)malloc(maxsize*sizeof(dst));
	dst *head=p;
	int l=5;int r=25;
	for(int i=0;i<5;i++,l++)   //zuoduizhan fuzhi
	{
		head->data[i]=l;
		head->top1=i;
	}
	for(int j=maxsize-1;j>head->top1;j--,r--)
	{
		head->data[j]=r;
		head->top2=j;
	}
	return head;
}
int POP(dst *head,int tag)//tag=1 push left ,tag=2,push right 
{
	if(tag==1)
	{
		if(head->top1==-1)
		{
			printf("the stackL is empty!");
		
		}
		else
		{
			head->data[(head->top1)]=NULL;
			head->top1--;
			return head->data[head->top1];
		}
	}
	else                       //tag==2
	{
		if(head->top2==maxsize)
		{
			printf("the stackR is empty!");
		}
		else
		{
			head->data[(head->top2)]=NULL;
			head->top2++;
			return head->data[head->top2];
		}
	}	
}

int PUSH(dst *head,int x,int tag)
{
	if(tag==1)
	{
		if(head->top2-head->top1==1)
		{
			printf("the stack is full");
		}
		else
		{
			head->data[(head->top1+1)]=x;
			head->top1++;
			return head->data[head->top1];
		}
	}
	else
	{
		if(head->top2-head->top1==1)
		{
			printf("The stack is full");
		}
		else
		{
			head->data[(head->top2-1)]=x;
			head->top2--;
			return head->data[head->top2];		
		}
	}
}



int main()
{
	dst *head;
	head=build();
	for(int i=head->top1;i>-1;i--)
	{
		printf("Left=%d\n",head->data[i]);
	}
	for(int i=head->top2;i<maxsize;i++)
	{
		printf("Rigth=%d\n",head->data[i]);
	}
	int popl;int tag1=1;   
	popl=POP(head,tag1);       // chuzuozhan
	int popr;int tag2=2;
	popr=POP(head,tag2);       //chu you zhan
	
	int pushl;int x=666;
	pushl=PUSH(head,x,tag1);
	int pushr;int y=888;
	pushr=PUSH(head,y,tag2);
	printf("-------------fenge----------\n");
//  text
	for(int i=head->top1;i>-1;i--)
	{
		printf("testL=%d\n",head->data[i]);
	}
	for(int i=head->top2;i<maxsize;i++)
	{
		printf("testR=%d\n",head->data[i]);
	}


	return 0;
}
