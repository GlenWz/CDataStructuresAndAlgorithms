#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct d{
	int data;
	int parent;	
}settype[MAXSIZE];

settype *builds()
{
	settype *s=(settype *)malloc((sizeof(settype)));
	int queue[]={0,1,-1,1,2,0,2,3,-1,3,4,0,4,5,2,5,6,-1,6,7,0,7,8,2,8,9,5,9,10,5,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	int v,d,p;
	while(front!=rear)
	{
		v=queue[front++];
		d=queue[front++];
		p=queue[front++];
		s[v]->data=d;
		s[v]->parent=p;
	}
	return s;
}
void PrintSet(settype *s)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		printf("Data:%d\tP:%d\n",s[i]->data,s[i]->parent);
	}
	printf("\n");
}
int FindP(settype *s,int x)
{
	int i;
	for(i=0;i<MAXSIZE&&s[i]->data!=x;i++)//这里条件要注意，while 和 for 的条件不要搞混了 
	{	
	}
	if(i>=MAXSIZE)
	{
		return -1;						// NOT Find
	}
	for(;s[i]->parent>=0;i=s[i]->parent)
	{
	}
	return i;	
}
void ChangParent(settype *s)
{
	s[0]->parent=-3;
	s[2]->parent=-2;
	s[5]->parent=-2;
}

void UnionS(settype *s,int x,int y)
{
	int root1,root2;
	root1=FindP(s,x);
	root2=FindP(s,y);
	if(root1!=root2)
	{
		if(abs(s[root1]->parent)>=abs(s[root2]->parent))
		{
			s[root1]->parent=s[root1]->parent+s[root2]->parent;
			s[root2]->parent=root1;
		
		}else 
		{
			s[root2]->parent=s[root1]->parent+s[root2]->parent;
			s[root1]->parent=root2;
		}
	}
}



int main()
{
	settype *s1=builds();
	PrintSet(s1);
	int x=5;
	int Par=FindP(s1,x);
	printf("the parent:\n%d",Par);
	ChangParent(s1);
	UnionS(s1,2,6);     //这里插入的2和5是data值，不是位置！ 
	printf("\n");
	PrintSet(s1);
}







