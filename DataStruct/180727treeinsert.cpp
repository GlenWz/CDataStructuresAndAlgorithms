#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

tree *build()
{
	int num;
	printf("the value ");
	scanf("%d",&num);
	if(num==-1)
	{
		return NULL;
	}else
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=num;
		s->left=build();
		s->right=build();
		return s;
	}	
}
void mid(tree *head)
{
	if(head)
	{
		mid(head->left);
		printf("mid=%d\n",head->data);
		mid(head->right);
	}
}
tree *insert(tree *head,int x)
{
	if(head->left==NULL||head->right==NULL)
	{
		tree *head=(tree*)malloc(sizeof(tree));
		head->data=x;
		head->left=NULL;
		head->right=NULL;
		
	}else
	{
		if(x<head->data)
		{
			head->left=insert(head->left,x);
		}else if(x>head->data)
		{
			head->right=insert(head->right,x);
		}
	}
	return head;
}


int main()
{
	tree *head,*ins,*del;
	head=build();
	mid(head);
	int x;
	printf("please input the value!");
	scanf("%d",&x);
	ins=insert(head,x);
	mid(ins); 
}
