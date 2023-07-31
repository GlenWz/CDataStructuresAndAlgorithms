#include <Stdio.h>
#include <stdlib.h>
#define maxsize 20

typedef struct d{
	int data[maxsize];
	int left;
	int right;
}linkq;

linkq *build()
{
	linkq *head=(linkq *)malloc(sizeof(linkq));
	int l=100; int r=6;
	for(int i=0;i<5;i++,l++)
	{
		head->data[i]=l;
		head->left=i;
	}
	for(int j=maxsize;j>head->left;j--,r++)
	{
		head->data[j]=r;
		head->right=j;
	}
	return head;
}
void schu(linkq *head)
{
/*	printf("%d\n",head->left);
	printf("%d\n",head->right);*/
	
	for(int i=head->left;i>-1;i--)
	{
		printf("L=%d\n",head->data[i]);
	}
	for(int j=head->right;j<maxsize;j++)
	{
		printf("R=%d\n",head->data[j]);
	}
	
}



int main()
{
	linkq *head;
	head=build();
	
	schu(head);
}
