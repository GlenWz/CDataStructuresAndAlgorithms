/*
������������ʵ������������������ʱ���������ɹ���
���Ǳ���ʵ�ִ������˺ܾö�û���ҵ�����Ĵ����,
����ʦ��ʱ�����ָ�㣬лл�� 
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

tree *buildt(int a[],int &n) //�����������Ľڵ��������洢������������� 
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
void PrintMid(tree *t)     //�ݹ�������������� 
{
	if(t==NULL)
	{
		return;
	}
	PrintMid(t->LChild);
	printf("%d->",t->data);
	PrintMid(t->RChild);
}
void MID(tree *t,tree **Pre)   //���������������� ��Pre��ʼΪNULL 
{
	if(t==NULL)
	{
		return;
	}else 
	{
		MID(t->LChild,Pre);   //�ݹ������� 
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
tree *Infirst(tree *t)   //���ҵ�һ���ڵ�return 
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
tree *Innext(tree *t)  //����һ���ڵ� 
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
void MidBL(tree *t)	  //�������������� 
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
	PrintMid(t);   								 //������� 
	printf("\n��������������:\n");
	tree *Pre=NULL;							   //Pre��¼��ʼֵ 
	MID(t,Pre); 							  //���������� 
	MidBL(t);								 //������������������ 
	

}








