/*
问题描述：在实现中序线索二叉树的时候，树创建成功，
但是遍历实现错误，找了很久都没有找到代码的错误点,
望老师有时间给予指点，谢谢！ 
*/

#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct d{
	int data;
	int ltag,rtag;
	struct d *LChild;
	struct d *RChild;
}tree;

tree *buildt(int a[],int &n) //创建树，树的节点采用数组存储，先序遍历创建 
{
	int num=a[n++];
	if(num==NULL)
	{
		return NULL;
	}
	tree *s=(tree *)malloc(sizeof(tree));
	s->data=num;
	s->ltag=0;
	s->rtag=0;
	s->LChild=buildt(a,n);
	s->RChild=buildt(a,n);
	return s;
}
void PrintMid(tree *t)     //递归中序遍历二叉树 
{
	if(t==NULL)
	{
		return;
	}
	PrintMid(t->LChild);
	printf("%d->",t->data);
	PrintMid(t->RChild);
}
void MID(tree *t,tree **Pre)   //二叉树中序线索化 ，Pre初始为NULL 
{
	if(t==NULL)
	{
		return;
	}else 
	{
		MID(t->LChild,Pre);   //递归左子树 
		if(t->LChild==NULL)
		{
			t->LChild=&Pre;
			t->ltag=1; 
		}
		if(Pre!=NULL&&Pre->RChild==NULL)
		{
			Pre->RChild=t;
			Pre->rtag=1;
		}
		Pre=t;
		MID(t->RChild,Pre);
	}
}
tree *Infirst(tree *t)   //查找第一个节点return 
{
	tree *ret=t;
	if(ret==NULL)
	{
		return NULL;
	}
	while(ret->ltag==0)
	{
		ret=ret->LChild;
	} 
	return ret;
}
tree *Innext(tree *t)  //找下一个节点 
{
	tree *Next;
	if(t->rtag==1)
	{
		Next=t->RChild;
	}else 
	{
		for(tree *q=t->RChild;q->ltag==0;q=q->LChild)
		{
			Next=q;
		}
	}
	return Next;
}
void MidBL(tree *t)	  //遍历线索二叉树 
{
	tree *p;
	p=Infirst(t);
	while(p)
	{
		printf("%d->",p->data);
		p=Innext(p);
	}
}

int main()
{
	int a[]={1,2,4,0,5,0,0,0,3,6,0,8,0,0,7,0,0,};
	int n=0;
	tree *t=buildt(a,n);
	PrintMid(t);   								 //中序遍历 
	printf("\n中序线索二叉树:\n");
	tree *Pre=NULL;							   //Pre记录初始值 
	MID(t,Pre); 							  //中序线索化 
	MidBL(t);								 //中序线索二叉树遍历 
	

}








