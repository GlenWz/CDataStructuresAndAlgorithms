#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	char data;
	struct d *left;
	struct d *right;
}tree;
tree *build()       //�ݹ���������� 
{
	char num;
	printf("please input  the num:");
	scanf("%s",&num);
	if(num=='0')
	{
		return NULL;
	}else 
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=num;
		s->left=build();
		s->right=build();
	}
}
int op(int a,int b,char c)    // a���� * b���� ����ret 
{
	int ret=a*b;
	return ret;
}
int Calculator(tree *h)
{
	int a,b;
	if(h!=NULL)
	{
	
		if(h->left!=NULL&&h->right!=NULL)
		{
			a=Calculator(h->left);
			b=Calculator(h->right);
			return op(a,b,h->data);//���h->data��ͷ����   '*' ���� 
		}else
		{
			return h->data-'0';   //����ɶ��Ҳ��֪�� 
		}
	}else 
	{	return 0;
	}
}
void last(tree *head)     //������� 
{
	if(head!=NULL)
	{
		last(head->left);
		last(head->right);
		printf("%c\t",head->data);
	}
	
}

int main()
{
	tree *t1=build();
	last(t1);
	printf("\nwo shi ni die!\n");
	int j=Calculator(t1);
	printf("%d\n",j);
	
}
