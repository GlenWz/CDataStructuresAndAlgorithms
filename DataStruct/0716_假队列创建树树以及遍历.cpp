#include <Stdio.h>
#include <Stdlib.h>
#define max 100

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

typedef struct n{
	int  data[max];
	int front,rear;
}qnode;

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	int Max[]={1,2,4,0,0,5,0,0,3,6,0,0,7,0,0,};
	for(int i=0;i<sizeof(Max)/sizeof(Max[0]);i++)
	{
		q->data[q->rear++]=Max[i];
	}
	return q;
}
tree *buildt(qnode *q)
{
	if(q->front==q->rear)
	{
		return NULL;
	}
	int num=q->data[q->front++];
	if(num==0)
	{
		return NULL;
	}else 
	{
		tree *s=(tree *)malloc(sizeof(tree));
		s->data=num;
		s->left=buildt(q);
		s->right=buildt(q); 	
		return s;
	}
}
void MidSeq(tree *t)
{
	if(t!=NULL)
	{
		MidSeq(t->left);
		printf("%d->",t->data);
		MidSeq(t->right);
	}
}
int DeepT(tree *t)
{
	int LD,RD;
	if(t==NULL)
	{
		return 0;
	}else
	 {
	 	LD=DeepT(t->left);
	 	RD=DeepT(t->right);
	 	return (LD>RD?LD:RD)+1;
	 }
}

int main()
{
	qnode *q=buildq();
	tree *t=buildt(q);
	MidSeq(t);
	int count=1;
	int DEEP=DeepT(t); 
	printf("Tree's deep is %d\n",DEEP);
	
	
	
}
